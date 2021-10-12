
NAME =		libft.a

SRCS =		ft_atoi.c		ft_bzero.c 		ft_calloc.c 	\
		ft_isalnum.c 		ft_isalpha.c 		ft_isascii.c 	\
      		ft_isdigit.c 		ft_isprint.c 		ft_itoa.c 	\
      		ft_memccpy.c 		ft_memchr.c 		ft_memcmp.c 	\
      		ft_memcpy.c 		ft_memmove.c 		ft_memset.c 	\
		ft_putchar_fd.c 	ft_putendl_fd.c 	ft_putnbr_fd.c 	\
     		ft_putstr_fd.c 		ft_split.c 		ft_strchr.c 	\
    		ft_strdup.c 		ft_strjoin.c 		ft_strlcat.c 	\
    		ft_strlcpy.c 		ft_strlen.c 		ft_strmapi.c 	\
     		ft_strncmp.c 		ft_strnstr.c 		ft_strrchr.c 	\
      		ft_strtrim.c 		ft_substr.c 		ft_tolower.c 	\
      		ft_toupper.c		ft_atol.c

BNS = 		ft_lstadd_back.c 	ft_lstadd_front.c 	ft_lstclear.c 	\
     		ft_lstdelone.c 		ft_lstiter.c 		ft_lstlast.c 	\
		ft_lstmap.c		ft_lstnew.c		ft_lstsize.c

OBJS = 		${SRCS:.c=.o}
BNS_OBJS =	${BNS:.c=.o}
HEAD =		libft.h
CC = 		gcc
CFLAGS =	-Wall -Wextra -Werror -c

all: 		$(NAME)
.c.o: 		$(HEAD)
		$(CC) $(CFLAGS) $< -o $@
$(NAME): 	$(OBJS) $(HEAD)
		ar -rcs $(NAME) $?
bonus:
		make OBJS="$(BNS_OBJS)" all
clean:
		rm -f $(OBJS) $(BNS_OBJS)
fclean: 	clean
		rm -f $(NAME)
re:		fclean all
.PHONY:    	all bonus clean fclean re
