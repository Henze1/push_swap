MAKEFLAGS += --no-print-directory

CC = cc

CFLAGS = -Wall -Wextra -Werror

ARGS = '57' '16' '14' '8'

HEADER = push_swap.h

LIBFT = Libft
LIBFT_NAME = libft.a

SRC = ft_main.c \
		ft_push_swap.c \
		ft_push_swap_utils.c \

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)
	@./$(NAME) $(ARGS)
	@make fclean

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)/$(LIBFT_NAME) .
	@$(CC) $(OBJ) $(LIBFT_NAME) -o $(NAME)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re