/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:09:26 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/01 15:17:39 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

#define BTN_LEFT 1
#define STDERR 2

typedef struct s_pos
{
	int	x;
	int	y;
} t_pos;

typedef struct s_player
{
	int		img_width;
	int		img_height;
	void	*img[4];
	t_pos	pos;
} t_player;

typedef struct s_game
{
	int		row_len;
	int		col_len;
	int		count[3];
	int		count_move;
	int		img_width;
	int		img_height;
	int		screen_width;
	int		screen_height;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*collectible;
	void	*space;
	void	*exit;
	void	*enemy;
	char	**map;
	t_player player;
	t_pos	exit_pos;
} t_game;

enum s_character
{
	CHAR_C	= 0x43,
	CHAR_P	= 0x50,
	CHAR_E	= 0x45,
	CHAR_0 	= 0x30,
	CHAR_1 	= 0x31
};

enum e_keys
{
	KEY_A = 0x0,		// 0	= LEFT - A
	KEY_D = 0x2,		// 2 	= RIGHT - D
	KEY_S = 0x1,		// 1 	= DOWN - S
	KEY_W = 0xd,		// 13	= UP - W
	KEY_ESC = 0x35,		// 53 	= EXIT
};

enum e_colors
{
	RED		= 0xff0000,
	GREEN	= 0x00ff00,
	BLUE 	= 0x0000ff,
	DARK 	= 0x181818,
	YELLOW	= 0xfff26e,
	WHITE	= 0xffffff,
};

char	**map_dup(char **map, size_t size);
int		get_map(t_game *game, const char *file_path);
int		check_walls(t_game *game);
int		check_file_path(const char *file_path);
int		check_character(t_game *game);
int		check_path(t_game *game);
void	print_map(char **lines);
void	free_game(t_game *game);
void	render_game(t_game *game);
void	update_player(t_game *game, const unsigned int idx);
void	get_pos(t_game *game);
int		key_hook(int keycode, t_game *game);
int		close_win(t_game *game);

#endif // SO_LONG
