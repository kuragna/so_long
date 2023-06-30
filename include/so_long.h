/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:09:26 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/30 15:40:30 by aabourri         ###   ########.fr       */
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
	void	*img;
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
	COLLECT = 67,
	PLAYER = 80,
	EXIT = 69,
	SPACE = 48,
	WALL = 49,	
};

enum e_keys
{
	LEFT	= 0x0,		// 0	= LEFT - A
	RIGHT	= 0x2,		// 2 	= RIGHT - D
	DOWN	= 0x1,		// 1 	= DOWN - S
	UP		= 0xd,		// 13	= UP - W
	ESC		= 0x35,		// 53 	= EXIT
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
void	update_player(t_game *game);
void	get_pos(t_game *game);
int		key_hook(int keycode, t_game *game);

#endif // SO_LONG
