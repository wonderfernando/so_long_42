# include "so_long.h"


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
}
int close_window(struct t_data *data)
{
   mlx_destroy_window(data->mlx,data->window);
   exit(0);
}
void render_map(struct t_data *data)
{
   void *java = mlx_xpm_file_to_image(data->mlx, "./textures/food.xpm", &data->img_width_size, &data->img_height_size);
   void *gruta = mlx_xpm_file_to_image(data->mlx, "./textures/portal.xpm", &data->img_width_size, &data->img_height_size);
   void * floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->img_width_size, &data->img_height_size);
   void * wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->img_width_size, &data->img_height_size);
   int x = 0;
   int y = 0;
   int pos_x = 0;
   int pos_y = 0;
   while (data->map->map[y] != NULL)
   {
     x = 0;
   
     pos_y = y * 80;
    
      while(data->map->map[y][x])
      {
         pos_x = x  * 80;
         if (data->map->map[y][x] == '1')
            mlx_put_image_to_window(data->mlx, data->window, wall, pos_x, pos_y);
         else if (data->map->map[y][x] == '0')
            mlx_put_image_to_window(data->mlx, data->window, floor, pos_x, pos_y);
         else if (data->map->map[y][x] == 'C')
            mlx_put_image_to_window(data->mlx, data->window, java, pos_x, pos_y);
         else if (data->map->map[y][x] == 'E')
            mlx_put_image_to_window(data->mlx, data->window, gruta, pos_x, pos_y);
         else if (data->map->map[y][x] == 'P'){
            data->jogador_pos_x = pos_x;
            data->jogador_pos_y = pos_y;
            mlx_put_image_to_window(data->mlx, data->window, data->jogador_img, pos_x, pos_y);
         }
         x++;
      }
      y++;
   }
}
void get_init_position(struct t_map *map)
{
   int x = 0;
   int y = 0;
   while (map->map[y] != NULL)
   {
      x = 0;
      while(map->map[y][x])
      {
         if (map->map[y][x] == 'P')
         {
            map->pos_x = x;
            map->pos_y = y;
            return;
         }
         x++;
      }
      y++;
   }
}
/* moves */
void move_right(struct t_data *data)
{
   data->map->map[data->map->pos_y][data->map->pos_x] = '0';
   data->map->pos_x++;
   data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
   data->jogador_img = mlx_xpm_file_to_image(data->mlx, "./textures/moving_right.xpm", &data->img_width_size, &data->img_height_size);
   data->steps++;
   //ft_printf("PASSOS: %d\n", data->steps);
}

void move_left(struct t_data *data)
{
   data->map->map[data->map->pos_y][data->map->pos_x] = '0';
   data->map->pos_x--;
   data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
   data->jogador_img =  mlx_xpm_file_to_image(data->mlx, "./textures/moving_left.xpm", &data->img_width_size, &data->img_height_size);
   data->steps++;
   //ft_printf("PASSOS: %d\n", data->steps);
}

void move_up(struct t_data *data)
{
   data->map->map[data->map->pos_y][data->map->pos_x] = '0';
   data->map->pos_y--;
   data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
   data->jogador_img = mlx_xpm_file_to_image(data->mlx, "./textures/moving_right.xpm", &data->img_width_size, &data->img_height_size);
   data->steps++;
   //ft_printf("PASSOS: %d\n", data->steps);
}
void move_down(struct t_data *data)
{
   data->map->map[data->map->pos_y][data->map->pos_x] = '0';
   data->map->pos_y++;
   data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
   data->jogador_img = mlx_xpm_file_to_image(data->mlx, "./textures/moving_right.xpm", &data->img_width_size, &data->img_height_size);
   data->steps++;
   //ft_printf("PASSOS: %d\n", data->steps);
}

int LEFT = 65361;
int RIGHT = 65363;
int UP = 65362;
int DOWN = 65364;

 
void check_win(struct t_data *data, int key)
{
   if (data->colated == data->colates)
   {
      if (key == LEFT && data->map->map[data->map->pos_y][data->map->pos_x - 1] == 'E')
      {
         ft_printf("VOCE VENCEU!\n");
         close_window(data);
      }
      else if (key == RIGHT && data->map->map[data->map->pos_y][data->map->pos_x + 1] == 'E')
      {
         ft_printf("VOCE VENCEU!\n");
         close_window(data);
      }
      else if (key == UP && data->map->map[data->map->pos_y - 1][data->map->pos_x] == 'E')
      {
         ft_printf("VOCE VENCEU!\n");
         close_window(data);
      }
      else if (key == DOWN && data->map->map[data->map->pos_y + 1][data->map->pos_x] == 'E')
      {
         ft_printf("VOCE VENCEU!\n");
         close_window(data);
      }
      
   }
}
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


void init_game(struct t_data *data, char **av, struct t_map *map)
{
      data->colates = 0;
      data->mlx = mlx_init();
      init_map(av[1], map, data); 
      data->window = mlx_new_window(data->mlx, data->width,data->heigth, "HUNTER X HUNTER");
      data->img_width_size = 80;
      data->img_height_size = 80;
      data->jogador_img =  mlx_xpm_file_to_image(data->mlx, "./textures/moving_right.xpm", &data->img_width_size, &data->img_height_size);
      data->steps = 0;
      data->colated = 0;
}
void init_map(const char *filename, struct t_map *map,struct t_data *data)
{
   int lines = 0;
   char *line;
   int fd_map = open(filename,O_RDONLY);
   while ((line = get_next_line(fd_map)) != NULL)
   {
      lines++;
      free(line);
   }
   close(fd_map);
   map->map = malloc(sizeof(char *) * (lines + 1));
   data->heigth = lines * 80; // a altura do mapa em pixels
   fd_map = open(filename,O_RDONLY);
   lines = 0;
   while ((line = get_next_line(fd_map)) != NULL)
   {
      map->map[lines] = ft_strdup(line);
      data->colates += count_char(line, 'C');
      if (map->map[lines] == NULL)
         map->pos_x = ft_strchr(line, 'P') - line;
      lines++;
      free(line);
   }
   close(fd_map);
   map->map[lines] = NULL;
   data->width = (ft_strlen(map->map[0]) - 1) * 80; // a largura do mapa em pixels
   data->map = map;
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
int validate_format_name_map(char *filename)
{
    char *format = ft_strchr(filename, '.');
    if (format == NULL || ft_strcmp(".ber", format) != 0)
      return ft_printf("ERROR: FORMATO ERRADO\n");
   return (0);
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