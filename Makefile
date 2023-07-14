# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabourri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/11 13:09:02 by aabourri          #+#    #+#              #
#    Updated: 2023/07/14 13:57:28 by aabourri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLX_FLAGS 	= -lmlx -framework OpenGL -framework AppKit
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
			  fill_screen.c \

SRC_BONUS	= $(addsuffix _bonus.c, $(basename .c, $(SRC))) animate_enemy_bonus.c

OBJS		= $(SRC:.c=.o)
OBJS_BONUS	= $(SRC_BONUS:.c=.o)

SRC_BONUS 	:= $(addprefix bonus/src/, $(SRC_BONUS))
SRC			:= $(addprefix mandatory/src/, $(SRC))


LIBFT		= ./libft/

LIB			= ./libft/libft.a

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIBFT)

bonus: $(LIB)
	@make "SRC=$(SRC_BONUS)"

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS) 
	$(CC) -o $@ $(OBJS) $(MLX_FLAGS) $(LIB)
clean: 
	make clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re LIB bonus
