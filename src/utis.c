/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:33:54 by ferda-si          #+#    #+#             */
/*   Updated: 2024/09/09 18:48:19 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	close_window(struct t_data *data)
{

	mlx_destroy_image(data->mlx, data->floor_img);
	mlx_destroy_image(data->mlx, data->jogador_img);
	mlx_destroy_image(data->mlx, data->food_img);
	mlx_destroy_image(data->mlx, data->portal_img);
	mlx_destroy_image(data->mlx, data->wall_img);
	mlx_clear_window(data->mlx, data->window);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	
	int y = 0;
	while (data->map->map[y])
	{
		free(data->map->map[y]);
		y++;
	}
	free(data->map->map);
	free(data->mlx);
	exit(0);
}

void	get_init_position(struct t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == 'P')
			{
				map->pos_x = x;
				map->pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	validate_format_name_map(char *filename)
{
	char	*format;

	format = ft_strchr(filename, '.');
	if (format == NULL || ft_strcmp(".ber", format) != 0)
		return (ft_printf("ERROR: FORMATO ERRADO\n"));
	return (0);
}



void	render(struct t_data *data, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * 80;
	pos_y = y * 80;
	if (data->map->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->wall_img, pos_x, pos_y);
	else if (data->map->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->floor_img , pos_x, pos_y);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->food_img, pos_x, pos_y);
	else if (data->map->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->portal_img, pos_x, pos_y);
	else if (data->map->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->window, \
			data->jogador_img, pos_x, pos_y);
}


void free_all(struct t_data *data)
{
	free(data->map->map);
	free(data->map);
}