# include "so_long.h"

/*
void render(struct t_data *data)
{
   int pos_x = 0;
   int pos_y = 0;
   void  *floor;
   void  *wall;
  // void *jogador;
   void *java = mlx_xpm_file_to_image(data->mlx, "./textures/food.xpm", &data->img_width_size, &data->img_height_size);
   void *gruta = mlx_xpm_file_to_image(data->mlx, "./textures/portal.xpm", &data->img_width_size, &data->img_height_size);
 
   floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->img_width_size, &data->img_height_size);
   wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->img_width_size, &data->img_height_size);
  // jogador = mlx_xpm_file_to_image(data->mlx, "./textures/moving_right.xpm", &data->img_width_size, &data->img_height_size);
  
   for(int y = 0; y <= 9; y++)
   {
      pos_y = y * 80;
      for(int x = 0; x <= 9; x++)
      {
         pos_x = x  * 80;
 
         if (pos_y == 0 || pos_x == 0 || x == 9 || y == 9)
            mlx_put_image_to_window(data->mlx, data->window, wall, pos_x, pos_y);
         else
            if (pos_y == 240)
                  mlx_put_image_to_window(data->mlx, data->window, java, pos_x, pos_y);
               else
                  mlx_put_image_to_window(data->mlx, data->window, floor, pos_x, pos_y);
      }

   }
   //mlx_put_image_to_window(data->mlx, data->window, data->jogador_img, data->jogador_pos_x, data->jogador_pos_y);
   mlx_put_image_to_window(data->mlx, data->window, gruta, pos_x/2, pos_y/2);
   mlx_put_image_to_window(data->mlx, data->window, java, pos_x/6, pos_y/2); 
   mlx_put_image_to_window(data->mlx, data->window, data->jogador_img, data->jogador_pos_x, data->jogador_pos_y);  
}*/


int LEFT = 65361;
int RIGHT = 65363;
int UP = 65362;
int DOWN = 65364;

int key_press(int key, struct t_data *data)
{
   if (key == 65307) //ESC
      close_window(data);
   check_win(data, key);
   if (key == RIGHT && data->map->map[data->map->pos_y][data->map->pos_x + 1] != '1') // move right
   {
      if (data->map->map[data->map->pos_y][data->map->pos_x + 1] == 'C')
         data->colated++;
      move_right(data);
   } 
   if (key == LEFT && data->map->map[data->map->pos_y][data->map->pos_x - 1] != '1')  // move left
   {
      if (data->map->map[data->map->pos_y][data->map->pos_x - 1] == 'C')
         data->colated++;
      move_left(data);
   }
   if (key == UP && data->map->map[data->map->pos_y - 1][data->map->pos_x] != '1') // move up  
   {
      if (data->map->map[data->map->pos_y - 1][data->map->pos_x] == 'C')
         data->colated++;
      move_up(data);
   }
   if (key == DOWN && data->map->map[data->map->pos_y + 1][data->map->pos_x] != '1') // move down
   {
      if (data->map->map[data->map->pos_y + 1][data->map->pos_x] == 'C')
         data->colated++;
      move_down(data);
   }
   ft_printf("PASSOS: %d\n", data->steps); 
   ft_printf("COLATEDS: %d %d\n", data->colated, data->colates); 
   render_map((struct t_data *)data);
}





int main(int ac, char **av)
{
   struct t_map map;
   int fd;
   struct t_data data;
   
   if (ac < 2)   {
      ft_printf("ERROR: DEFINA O MAPA A SER UTILIZADO!\n");
      return (1);
   }
   if (validate_format_name_map(av[1]) == 0)
   {
      fd = open(av[1],O_RDONLY);
      if(fd == -1)
      {
         ft_printf("ERROR: MAPA NÃO ENCONTRADO!\n");
         return (1);
      }
      init_game(&data, av, &map);
      render_map(&data);
      get_init_position(&map);
      mlx_hook(data.window, 17, 0, &close_window, &data);
      mlx_key_hook(data.window, &key_press, &data);
      mlx_loop(data.mlx);
   }

}