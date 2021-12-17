
NAME			=	push_swap
CHECKER			=	checker

SRCS			=	sources/push_swap.c						\
					sources/unify_string.c					\
					sources/accessory_functions.c			\
					sources/check_arguments.c				\
					sources/fill_data.c						\
					sources/list_functions.c				\
					sources/sort_few_numbers.c				\
					sources/sort_many_numbers.c				\
					sources/sort_three_elements.c			\
					sources/stack_a_movements.c				\
					sources/stack_b_movements.c				\
					sources/terminate.c

BNS_SRCS		=	bonus/sources/bonus_a_movements.c		\
					bonus/sources/bonus_b_movements.c		\
					bonus/sources/bonus_ab_movements.c		\
					bonus/sources/bonus_checker.c			\
					sources/check_arguments.c				\
					sources/fill_data.c						\
					sources/list_functions.c				\
					sources/terminate.c						\
					sources/unify_string.c					\
					bonus/get_next_line/get_next_line.c		\
					bonus/get_next_line/get_next_line_utils.c

OBJS			=	$(SRCS:.c=.o)
BNS_OBJS		=	$(BNS_SRCS:.c=.o)

DEPS 			= 	$(SRCS:.c=.d)
BNS_DEPS 		= 	$(BNS_SRCS:.c=.d)

HEAD			=	includes/push_swap.h
LIBFT			=	libft.a
LIBFT_PATH		=	./libft/
LIBFTMAKE		=	$(MAKE) all -sC $(LIBFT_PATH)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -MMD

all:				lib $(NAME)

bonus:				lib $(CHECKER)

.c.o:
					$(CC) $(CFLAGS) -Iincludes/ -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

$(CHECKER):			$(BNS_OBJS)
					$(CC) $(CFLAGS) $(BNS_OBJS) -L$(LIBFT_PATH) -lft -o $(CHECKER)

lib:
					$(LIBFTMAKE)

clean:
					$(MAKE)	clean -sC $(LIBFT_PATH)
					rm -rf $(OBJS) $(BNS_OBJS) $(BNS_DEPS) $(DEPS)

fclean:				clean
					$(MAKE)	fclean -sC $(LIBFT_PATH)
					rm -rf $(NAME) $(CHECKER)

re:					fclean all
.PHONY:				all lib bonus clean fclean re
-include			$(OBJS:.o=.d) $(BNS_OBJS:.o=.d)
