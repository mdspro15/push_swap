.PHONY : all clean fclean re

NAME = push_swap
FLAGS = -Wall -Wextra -Werror
OPDIR = op
LIB = libft/libft.a
SRC = $(OPDIR)/swap.c \
	  $(OPDIR)/push.c \
	  $(OPDIR)/rotate.c \
	  $(OPDIR)/reverse_rotate.c \
	  list.c check_arg.c is_sorted.c is_duplicated.c \
	  sort.c small_sort.c get_pivot.c free.c push_swap.c \
	  sort_big.c sort_big2.c min_max.c \
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJ): %.o: %.c push_swap.h
	gcc $(FLAGS) -c $< -o $@

$(LIB):
	make -C libft

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

