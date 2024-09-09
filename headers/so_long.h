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
   void *jogador_img;
   int colates;
   int colated;
   int steps;
   struct t_map *map;
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