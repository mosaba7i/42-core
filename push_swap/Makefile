NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
SRCS = $(SRCDIR)/main.c $(SRCDIR)/parsing.c $(SRCDIR)/checks.c $(SRCDIR)/normalize.c \
       $(SRCDIR)/small_sort.c $(SRCDIR)/radix.c $(SRCDIR)/stack_utils.c \
       $(SRCDIR)/instructions/sa.c $(SRCDIR)/instructions/sb.c $(SRCDIR)/instructions/ss.c \
       $(SRCDIR)/instructions/pa.c $(SRCDIR)/instructions/pb.c \
       $(SRCDIR)/instructions/ra.c $(SRCDIR)/instructions/rb.c $(SRCDIR)/instructions/rr.c \
       $(SRCDIR)/instructions/rra.c $(SRCDIR)/instructions/rrb.c $(SRCDIR)/instructions/rrr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
