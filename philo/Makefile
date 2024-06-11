NAME		=	philo

SRC			= close.c init.c main.c validation.c\

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror -g

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

re:			fclean all

git:
	git add .
	git commit -m "update"
	git push

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

.PHONY:		all clean fclean re
