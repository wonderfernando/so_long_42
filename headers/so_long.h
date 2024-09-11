/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ferda-si <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:23:50 by ferda-si          #+#    #+#             */
/*   Updated: 2024/08/30 16:23:53 by ferda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <stdlib.h>
# include<stdio.h>
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

struct t_data{
   void *mlx;
   void *window;
   int width;
   int heigth;
   int img_width_size;
   int img_height_size;
   int jogador_pos_x;
   int jogador_pos_y;

   int colates;
   int colated;
   int steps;
   struct t_map *map;
   void *wall_img;
   void *floor_img;
   void *jogador_img;
   void *food_img;
   void *portal_img;
};

struct t_map{
   char **map;
   int pos_x;
   int pos_y;
} ;

char *ft_strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *ft_substr(const char *s, unsigned int start, size_t len);
char **ft_split(const char *s, char c);
void init_map(const char *filename, struct t_map *map,struct t_data *data);
void init_game(struct t_data *data, char **av, struct t_map *map);
int count_char(char *str, char c);
void move_up(struct t_data *data);
void move_down(struct t_data *data);
void move_left(struct t_data *data);
void move_right(struct t_data *data);
void check_win(struct t_data *data, int key);
void	*load_texture(struct t_data *data, char *path_image);
void	init_values(struct t_data *data, char **av, struct t_map *map);
int	close_window(struct t_data *data);
void    render(struct t_data *data, int x, int y);
void	render_map(struct t_data *data);
int	validate_format_name_map(char *filename);
char get_element(struct t_data *data, int pos_y, int pos_x);
void	get_init_position(struct t_map *map);
void free_all(struct t_data *data);