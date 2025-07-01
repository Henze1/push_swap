CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
LIBFT = libft
LIBFT_A = $(LIBFT)/libft.a

OBJ_DIR = build/objects
OUTPUT_DIR = build/outputs

TARGET = $(OUTPUT_DIR)/$(NAME)
LIBFT_OUTPUT = $(OUTPUT_DIR)/libft.a

SRC = main.c \
      service/push_swap.c \
      service/push_swap_utils.c \
      service/stack_utils.c \
      service/sort/sort.c \
      service/sort/sort_utils.c \
      service/sort/sort_large_scale.c \
      service/validations/validation.c \
      service/validations/validation_utils.c \
      service/operations/operations_push.c \
      service/operations/operations_swap.c \
      service/operations/operations_rotate.c \
      service/operations/operations_reverse_rotate.c \

HEADERS = headers/push_swap.h \
			headers/validation.h \
			headers/operations.h \
			headers/stack_utils.h \
			headers/sort.h \

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(TARGET)

$(TARGET): $(OBJ) $(LIBFT_OUTPUT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_OUTPUT) -o $(TARGET)

$(LIBFT_OUTPUT): $(LIBFT_A)
	mkdir -p $(OUTPUT_DIR)
	cp $< $@

$(LIBFT_A):
	make -C $(LIBFT)

$(OBJ_DIR)/%.o: %.c $(HEADERS) Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(OUTPUT_DIR)/$(NAME)
	rm -f $(OUTPUT_DIR)/libft.a
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
