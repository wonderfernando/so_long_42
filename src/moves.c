/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:47:29 by ferda-si          #+#    #+#             */
/*   Updated: 2024/09/09 15:15:27 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*load_texture(struct t_data data, char *path_image)
{
	return (mlx_xpm_file_to_image(data->mlx,
			path_image, &data->img_width_size, &data->img_height_size));
}

void	move_right(struct t_data *data)
{
	char	*path_image;

	path_image = "./textures/moving_left.xpm";
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_x++;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, path_image);
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}

void	move_left(struct t_data *data)
{
	char	*path_image;

	path_image = "./textures/moving_left.xpm";
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_x--;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, path_image);
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}

void	move_up(struct t_data *data)
{
	char	*path_image;

	path_image = "./textures/moving_right.xpm";
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_y--;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, path_image);
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}

void	move_down(struct t_data *data)
{
	char	*path_image;

	path_image = "./textures/moving_right.xpm";
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_y++;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, path_image);
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}
