/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:15:38 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:15:55 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <errno.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

# define TRUE (1)
# define FALSE (0)
# define BTN_LEFT (1)
# define STDERR (2)
# define WHITE (0xffffff)
# define DARK (0x181818)

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
	void		*imgs[4];
	char		**map;
	t_player	player;
	t_enemy		enemy;
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

enum e_keys
{
	KEY_A = 0x0,
	KEY_D = 0x2,
	KEY_S = 0x1,
	KEY_W = 0xd,
	KEY_ESC = 0x35,
};

enum e_imgs
{
	SPACE = 0,
	WALL,
	COLLECTIBLE,
	EXIT,
};

char	**map_dup(char **map, size_t size);
void	get_images(t_game *game);
int		get_map(t_game *game, const char *file_path);
int		check_walls(char **map, int col_len, int row_len);
int		check_file_path(const char *file_path);
int		check_character(char **map, int *count);
int		check_player_path(t_game *game);
void	render_game(t_game *game);
void	update_player(t_game *game, void **imgs);
void	get_pos(char **map, t_pos *player);
void	start_game(t_game *game);
void	print_error(char **map, const char *err_msg);
void	put_image(t_game *game, void *img, int x, int y);
void	fill_screen(t_game *game, const char *str);
int		key_hook(int keycode, t_game *game);
int		animate_enemy(t_game *game);

#endif // SO_LONG_BONUS
