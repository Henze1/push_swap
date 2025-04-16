CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

HEADER = push_swap.h

SRC = ft_main.c \
		ft_push_swap.c \
		ft_push_swap_utils.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re