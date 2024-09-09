#include "so_long.h";

int	ft_strcmp(char *s1, char *s2)
{
	int i;
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int close_window(struct t_data *data)
{
   mlx_destroy_window(data->mlx,data->window);
   exit(0);
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



int validate_format_name_map(char *filename)
{
    char *format = ft_strchr(filename, '.');
    if (format == NULL || ft_strcmp(".ber", format) != 0)
      return ft_printf("ERROR: FORMATO ERRADO\n");
   return (0);
}