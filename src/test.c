void	move_left(struct t_data *data)
{
	data->map->map[data->map->pos_y][data->map->pos_x] = '0';
	data->map->pos_x--;
	data->map->map[data->map->pos_y][data->map->pos_x] = 'P';
	data->jogador_img = mlx_xpm_file_to_image(data->mlx, "./textures/moving_left.xpm", &data->img_width_size, &data->img_height_size);
	data->steps++;
	ft_printf("PASSOS: %d\n", data->steps);
}