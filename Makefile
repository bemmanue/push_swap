
NAME 			=	push_swap

SRCS			=	sources/push_swap.c			\
					sources/stack_a_movements.c	\
					sources/stack_b_movements.c	\
					sources/list_functions.c	\
					sources/accessory_functions.c	\
					sources/sort_few_numbers.c	\
					sources/check_arguments.c	\
					sources/sort_three_elements.c\
					sources/sort_many_numbers.c	\
					sources/fill_data.c

LIBFT			=	./libft/libft.a
HEAD			=	includes/push_swap.h

CC 				= 	gcc
CFLAGS 			=	-Wall -Wextra -Werror

all: 			$(NAME)

$(NAME): 		$(OBJS) $(HEAD) $(LIBFT)
				$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(HEAD)
