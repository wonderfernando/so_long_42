/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:53:17 by ferda-si          #+#    #+#             */
/*   Updated: 2024/09/09 18:34:38 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	check_win(struct t_data *data, int key)
{
	int	new_pos_x;
	int	new_pos_y;

	new_pos_x = data->map->pos_x;
	new_pos_y = data->map->pos_y;
	if (data->colated == data->colates)
	{
		if (key == 65361 && \
			data->map->map[data->map->pos_y][data->map->pos_x - 1] == 'E')
			new_pos_x = data->map->pos_x - 1;
		else if (key == 65363 && \
			data->map->map[data->map->pos_y][data->map->pos_x + 1] == 'E')
			new_pos_x = data->map->pos_x + 1;
		else if (key == 65362 && \
				data->map->map[data->map->pos_y - 1][data->map->pos_x] == 'E')
			new_pos_y = data->map->pos_y - 1;
		else if (key == 65364 && \
				data->map->map[data->map->pos_y + 1][data->map->pos_x] == 'E')
			new_pos_y = data->map->pos_y + 1;
		if (data->map->map[new_pos_y][new_pos_x] == 'E')
		{
			ft_printf("YOU WIN!\n");
			close_window(data);
		}
	}
}

void	render_map(struct t_data *data)
{
	int		x;
	int		y;
	int		pos_x;
	int		pos_y;

	x = -1;
	y = -1;
	pos_x = 0;
	pos_y = 0;
	
	mlx_clear_window(data->mlx, data->window);
	while (data->map->map[++y] != NULL)
	{
		x = -1;
		pos_y = y * 80;
		while (data->map->map[y][++x])
		{
			pos_x = x * 80;
			render(data, x, y);
		}
	}
}

void	init_values(struct t_data *data, char **av, struct t_map *map)
{
	data->colates = 0;
	data->mlx = mlx_init();
	init_map(av[1], map, data);
	data->window = mlx_new_window(data->mlx, data->width, \
	data->heigth, "HUNTER X HUNTER");
	data->img_width_size = 80;
	data->img_height_size = 80;
	data->jogador_img = load_texture(data, "./textures/moving_right.xpm");
	data->steps = 0;
	data->colated = 0;
	data->food_img = load_texture(data, "./textures/food.xpm");
	data->portal_img = load_texture(data, "./textures/portal.xpm");
	data->wall_img = load_texture(data, "./textures/wall.xpm");
	data->floor_img = load_texture(data, "./textures/floor.xpm");
	data->jogador_pos_x = 0;
	data->jogador_pos_y = 0;
}

void	init_map(const char *filename, struct t_map *map, struct t_data *data)
{
	char	*line;
	int		fd_map;
	int		lines;

	lines = 0;
	fd_map = open(filename, O_RDONLY);
	line = get_next_line(fd_map);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd_map);
	}
	close(fd_map);
	map->map = malloc(sizeof(char *) * (lines + 1));
	data->heigth = lines * 80;
	fd_map = open(filename, O_RDONLY);
	lines = 0;
	line = get_next_line(fd_map);
	while (line != NULL)
	{
		map->map[lines] = ft_strdup(line);
		data->colates += count_char(line, 'C');
		if (count_char(line, 'C') > 0)
		{
			map->pos_x = ft_strchr(line, 'P') - line;
			data->jogador_pos_x = map->pos_x * 80;
			data->jogador_pos_y = lines * 80;
		}	
		lines++;
		free(line);
		line = get_next_line(fd_map);
	}
	free(line);
	close(fd_map);
	map->map[lines] = NULL;
	data->width = (ft_strlen(map->map[0]) - 1) * 80;
	data->map = map;
}

void	*load_texture(struct t_data *data, char *path_image)
{
	return (mlx_xpm_file_to_image(data->mlx,
			path_image, &data->img_width_size, &data->img_height_size));
}
