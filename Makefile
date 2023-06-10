NAME	= so_long
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -fr
SRC		= main.c

$(NAME): all


$(NAME):
	$(CC) -o $@ -lm $(CFLAGS) $(SRC)
clean:
	$(RM)
fclean:
	$(RM)

re: fclean all

.PHONY: all clean fclean re
