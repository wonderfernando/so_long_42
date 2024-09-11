cc -I minilibx-linux/ main.c minilibx-linux/libmlx_Linux.a  


sudo apt update \
sudo apt install libx11-dev libxext-dev \
sudo apt install build-essential

cc -I headers/ -I ft_printf -I minilibx-linux/ src/get_next_line.c src/get_next_line_utils.c src/split.c main.c minilibx-linux/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -lm


cc -I headers/ -I ft_printf -I minilibx-linux/ src/*.c main.c minilibx-linux/libmlx_Linux.a ft_printf/libftprintf.a -lXext -lX11 -lm