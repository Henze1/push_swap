CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = push_swap
LIBFT = ../libft
LIBFT_NAME = libft.a
BUILD_DIR = objects
OUTPUT_DIR = outputs

SRC = ../main.c \
      ../service/push_swap.c \
      ../service/push_swap_utils.c \
      ../service/stack_utils.c \
      ../service/sort/sort.c \
      ../service/sort/sort_utils.c \
      ../service/sort/sort_large_scale.c \
      ../service/validations/validation.c \
      ../service/validations/validation_utils.c \
      ../service/operations/operations_push.c \
      ../service/operations/operations_swap.c \
      ../service/operations/operations_rotate.c \
      ../service/operations/operations_reverse_rotate.c \

OBJ = $(patsubst ../%.c, $(BUILD_DIR)/%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	mkdir -p $(OUTPUT_DIR)
	cp $(LIBFT)/$(LIBFT_NAME) $(OUTPUT_DIR)/
	make fclean -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(OUTPUT_DIR)/$(LIBFT_NAME) -o $(OUTPUT_DIR)/$(NAME)

$(BUILD_DIR)/%.o: ../%.c ../headers/push_swap.h ../headers/validation.h ../headers/operations.h ../headers/stack_utils.h Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
	rm -f $(OUTPUT_DIR)/$(LIBFT_NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re