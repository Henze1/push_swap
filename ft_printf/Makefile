CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

LIBFT = Libft

SRC = ft_printaddr.c \
	ft_printchar.c \
	ft_printf.c \
	ft_printstring.c \
	ft_printdecimal.c \
	ft_printunsigned.c \
	ft_printhexadecimal.c \

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp Libft/libft.a .
	cp libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
