#include "so_long.h";

void	check_win(struct t_data *data, int key)
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