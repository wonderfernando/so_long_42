# include "so_long.h"
char get_element(struct t_data *data, int pos_y, int pos_x)
{
	return (data->map->map[data->map->pos_y][data->map->pos_x - 1]);
}

int key_press(int key, struct t_data *data)
{
   int LEFT = 65361;
   int RIGHT = 65363;
   int UP = 65362;
   int DOWN = 65364;

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
   render_map(data);
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
      close(fd);
      init_values(&data, av, &map);
      render_map(&data);
      get_init_position(&map);
  
      mlx_hook(data.window, 17, 0, &close_window, &data);
      mlx_key_hook(data.window, &key_press, &data);
      mlx_loop(data.mlx);
   }

}
