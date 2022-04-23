NAME = push_swap

GCC = CC
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft
LIBFT_MAKE = cd $(LIBFT_DIR) && make all
LIBFT_INC = -L $(LIBFT_DIR) -lft

SRC_DIR = src
SRC = src/main.c src/lists_functions.c src/main_algorithm.c \
	  src/misc.c src/moving.c src/parser.c src/push.c src/rotate.c \
	  src/quick_sortin_arr.c src/reverce_rotate.c src/rotate_options.c \
	  src/score_functions.c src/sorted.c src/stop.c src/swap.c src/utils_functions.c \

INC_DIR = includes
INC = includes/push_swap.h

OBJ_DIR = obj
OBJ = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

$(NAME): $(OBJ) $(INC)
		$(LIBFT_MAKE)
		$(GCC) $(OBJ) $(LIBFT_INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(GCC) $(CFLAGS) -c $< -o $@ -I $(INC)

$(OBJ): $(INC) | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

all: $(NAME)

clean: 
	rm -rf ${OBJ_DIR}
	cd $(LIBFT_DIR) && make clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re 

