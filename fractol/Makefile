NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

MLX_DIR = mlx
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

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
