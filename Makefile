NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g3 -lmlx -framework OpenGL -framework AppKit -fsanitize=address
RM			= rm -fr
SRC			= main.c \
			  check_character.c \
			  check_file_path.c \
			  check_player_path.c \
			  check_walls.c \
			  get_map.c \
			  get_pos.c \
			  get_images.c \
			  render_game.c \
			  update_player.c \
			  start_game.c \
			  map_dup.c \
			  print_error.c \

SRC_BONUS	= $(SRC) animate_enemy.c 

SRC_BONUS 	:= $(addprefix bonus/src/, $(SRC_BONUS))

SRC			:= $(addprefix mandatory/src/, $(SRC))

LIBFT		= ./libft/

LIB			= ./libft/libft.a

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIBFT)

bonus: $(SRC_BONUS) $(LIB)
	$(CC) -o $(NAME) $(CFLAGS) $^ $(LIB)

$(NAME): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(LIB)
clean:
	make clean -C $(LIBFT)
fclean:
	make fclean -C $(LIBFT)
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re LIB bonus
