
NAME			=	push_swap

SRCS			=	sources/push_swap.c				\
					sources/accessory_functions.c	\
					sources/check_arguments.c		\
					sources/check_set.c				\
					sources/check_string.c			\
					sources/fill_data.c				\
					sources/list_functions.c		\
					sources/sort_few_numbers.c		\
					sources/sort_many_numbers.c		\
					sources/sort_three_elements.c	\
					sources/stack_a_movements.c		\
					sources/stack_b_movements.c		\
					sources/terminate.c

OBJS			=	$(SRCS:.c=.o)

LIBFT			=	libft.a
LIBFT_PATH		=	./libft/
LIBFTMAKE		=	$(MAKE) all -sC $(LIBFT_PATH)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

all:				lib $(NAME)

.c.o:
					$(CC) $(CFLAGS) -I./includes/ -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

lib:
					$(LIBFTMAKE)

clean:
					$(MAKE)	clean -sC $(LIBFT_PATH)
					rm -rf $(OBJS)

fclean:				clean
					$(MAKE)	fclean -sC $(LIBFT_PATH)
					rm -rf $(NAME)

re:					fclean all
.PHONY:				all lib clean fclean re
