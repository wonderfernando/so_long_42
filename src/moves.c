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

void	move_right(struct t_data *data)
{
	char	*path_image;

	if (data->jogador_img != NULL)
		mlx_destroy_image(data->mlx, data->jogador_img);	
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_x++;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, "./textures/moving_right.xpm");
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}

void	move_left(struct t_data *data)
{
	char	*path_image;

	if (data->jogador_img != NULL)
		mlx_destroy_image(data->mlx, data->jogador_img);	
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_x--;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, "./textures/moving_left.xpm");
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}

void	move_up(struct t_data *data)
{
	char	*path_image; 

	if (data->jogador_img != NULL)
		mlx_destroy_image(data->mlx, data->jogador_img);	
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_y--;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = load_texture(data, "./textures/moving_right.xpm");
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}

void	move_down(struct t_data *data)
{
	char	*path_image;

	if (data->jogador_img != NULL)
		mlx_destroy_image(data->mlx, data->jogador_img);	
	data->jogador_img = load_texture(data, "./textures/moving_right.xpm");
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_y++;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}
