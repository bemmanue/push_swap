
NAME 			=	push_swap

SRCS			=	sources/push_swap.c			\
					sources/movements.c			\
					sources/list_functions.c	\
					sources/print.c				\
					sources/sort_numbers.c

LIBFT			=	./libft/libft.a
HEAD			=	includes/push_swap.h

CC 				= 	gcc
CFLAGS 			=	-Wall -Wextra -Werror

all: 			$(NAME)

$(NAME): 		$(OBJS) $(HEAD) $(LIBFT)
				$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(HEAD)
