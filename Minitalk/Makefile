NAME1 = server
NAME2 = client

CC = cc
FLAGS = -Wall -Wextra -Werror

all: $(NAME1) $(NAME2)

$(NAME1): server.o
	$(CC) $(FLAGS) server.o -o $(NAME1)

$(NAME2): client.o
	$(CC) $(FLAGS) client.o -o $(NAME2)

server.o: server.c
	$(CC) $(FLAGS) -c server.c -o server.o

client.o: client.c
	$(CC) $(FLAGS) -c client.c -o client.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all
.PHONY: all clean fclean re