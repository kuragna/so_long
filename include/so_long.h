/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:09:26 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/22 20:28:08 by aabourri         ###   ########.fr       */
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

typedef struct s_vector
{
	int	x;
	int	y;
} t_vector;

typedef struct s_player
{
	int	img_width;
	int	img_height;
	void	*img;
	t_vector position;
} t_player;

typedef struct s_game
{
	int	row_len;
	int	col_len;
	int	count[3];
	int	count_move;
	int	img_width;
	int	img_height;
	int	screen_width;
	int	screen_height;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*collectible;
	void	*space;
	void	*exit;
	void	*enemy;
	char	**map;
	t_player player;
	t_vector exit_pos;
} t_game;

enum e_keys
{
	A 	= 0X0,		// 0	= LEFT
	D 	= 0X2,		// 2 	= RIGHT
	S 	= 0X1,		// 1 	= DOWN
	W 	= 0Xd,		// 13	= UP
	ESC = 0X35,		// 53 	= EXIT
};

enum e_colors
{
	RED		= 0XFF0000,
	GREEN	= 0X00FF00,
	BLUE 	= 0X0000FF,
	DARK 	= 0X181818,
	YELLOW	= 0XFFF26E,
	WHITE	= 0XFFFFFF,
};

void	get_map(t_game *game, const char *file_path);
int		check_walls(t_game *game);
int		check_file_path(const char *file_path);
int		check_c_e_p(t_game *game);
void	print_map(char **lines);

#endif
