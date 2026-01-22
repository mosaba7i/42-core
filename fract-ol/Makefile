NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/init.c \
       $(SRC_DIR)/events.c \
       $(SRC_DIR)/render.c \
       $(SRC_DIR)/mandelbrot.c \
       $(SRC_DIR)/julia.c \
       $(SRC_DIR)/utils.c \
       $(SRC_DIR)/utils2.c \
       $(SRC_DIR)/colors.c

OBJS = $(SRCS:.c=.o)


all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJS) src/fractol.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean


fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
