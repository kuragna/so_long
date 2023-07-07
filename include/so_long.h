/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:09:26 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/07 19:31:35 by aabourri         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define BTN_LEFT 1
# define STDERR 2

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	int		flag;
	void	*imgs_left[3];
	void	*imgs_down[3];
	void	*imgs_up[3];
	void	*imgs_right[3];
	t_pos	pos;
}	t_player;

typedef struct s_enemy
{
	int		flag;
	int		count;
	void	*imgs[4];
}	t_enemy;

typedef struct s_game
{
	int			row_len;
	int			col_len;
	int			count_move;
	int			img_width;
	int			img_height;
	int			screen_width;
	int			screen_height;
	int			count;
	int			end;
	void		*mlx;
	void		*win;
	void		*wall;
	void		*collectible;
	void		*space;
	void		*exit;
	char		**map;
	t_player	player;
	t_enemy		enemy;
	t_pos		exit_pos;
}	t_game;

enum e_character
{
	CHAR_C = 0x43,
	CHAR_P = 0x50,
	CHAR_E = 0x45,
	CHAR_0 = 0x30,
	CHAR_1 = 0x31,
	CHAR_N = 0x4e,
};

// 0 = left = A
// 2 = right = D
// 1 = down = S
// 13 = up = W
// 53 = exit = ESC

enum e_keys
{
	KEY_A = 0x0,
	KEY_D = 0x2,
	KEY_S = 0x1,
	KEY_W = 0xd,
	KEY_ESC = 0x35,
};

enum e_colors
{
	RED = 0xff0000,
	GREEN = 0x00ff00,
	BLUE = 0x0000ff,
	DARK = 0x181818,
	YELLOW = 0xfff26e,
	WHITE = 0xffffff,
};

char	**map_dup(char **map, size_t size);
void	get_images(t_game *game);
int		get_map(t_game *game, const char *file_path);
int		check_walls(char **map, int col_len, int row_len);
int		check_file_path(const char *file_path);
// int		check_character(t_game *game);
int		check_character(char **map, int *count);
int		check_player_path(t_game *game);
void	print_map(char **lines);
void	free_game(t_game *game);
void	render_game(t_game *game);
void	update_player(t_game *game, void **imgs);
void	get_pos(char **map, t_pos *player, t_pos *exit);
void	start_game(t_game *game);
void	print_error(char **map, const char *err_msg);
void	put_image(t_game *game, void *img, int x, int y);
int		key_hook(int keycode, t_game *game);
int		animate_enemy(t_game *game);


#endif // SO_LONG
