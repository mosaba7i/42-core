NAME1 = server
NAME2 = client

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): server.c
	$(CC) $(FLAGS) server.c -o $(NAME1)

$(NAME2): client.c
	$(CC) $(FLAGS) client.c -o $(NAME2)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all
.PHONY: all clean fclean re