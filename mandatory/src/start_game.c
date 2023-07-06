/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:29:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/06 18:41:42 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	end_game(t_game *game, const char *msg)
{
	(void)msg;
	int	y;
	int	x;

	y = 0;
	while (y < (game->screen_height / game->img_height))
	{
		x = 0;
		while (x < (game->screen_width / game->img_width))
		{
			mlx_pixel_put(game->mlx, game->win, x, y, DARK);
			x++;
		}
		y++;
	}
}

static void	move_up_down(int keycode, t_game *game)
{
	t_pos	*pos;

	pos = &game->player.pos;
	if (keycode == KEY_W && game->map[pos->y - 1][pos->x] != CHAR_1)
	{
		if (game->map[pos->y - 1][pos->x] == CHAR_E && game->count[2] > 0)
			return ;
		put_image(game, game->space, pos->x, pos->y);
		pos->y -= 1;
		update_player(game, game->player.imgs_up);
		if (game->map[pos->y][pos->x] == CHAR_E && game->count[2] == 0)
			game->end = TRUE;
	}
	if (keycode == KEY_S && game->map[pos->y + 1][pos->x] != CHAR_1)
	{
		if (game->map[pos->y + 1][pos->x] == CHAR_E && game->count[2] > 0)
			return ;
		put_image(game, game->space, pos->x, pos->y);
		pos->y += 1;
		update_player(game, game->player.imgs_down);
		if (game->map[pos->y][pos->x] == CHAR_E && game->count[2] == 0)
			game->end = TRUE;
	}
}

static void	move_left_right(int keycode, t_game *game)
{
	t_pos	*pos;

	pos = &game->player.pos;
	if (keycode == KEY_A && game->map[pos->y][pos->x - 1] != CHAR_1)
	{
		if (game->map[pos->y][pos->x - 1] == CHAR_E && game->count[2] > 0)
			return ;
		put_image(game, game->space, pos->x, pos->y);
		pos->x -= 1;
		update_player(game, game->player.imgs_left);
		if (game->map[pos->y][pos->x] == CHAR_E && game->count[2] == 0)
			game->end = TRUE;
	}
	if (keycode == KEY_D && game->map[pos->y][pos->x + 1] != CHAR_1)
	{
		if (game->map[pos->y][pos->x + 1] == CHAR_E && game->count[2] > 0)
			return ;
		put_image(game, game->space, pos->x, pos->y);
		pos->x += 1;
		update_player(game, game->player.imgs_right);
		if (game->map[pos->y][pos->x] == CHAR_E && game->count[2] == 0)
			game->end = TRUE;
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	if (game->end == TRUE)
		return (0);
	if (game->player.flag == 2)
		game->player.flag = 0;
	move_up_down(keycode, game);
	move_left_right(keycode, game);
	game->player.flag += 1;
	return (0);
}

void	start_game(t_game *game)
{	
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		print_error(game, "Error: Could not initial mlx");
	get_images(game);
	game->screen_width = game->row_len * game->img_width;
	game->screen_height = game->col_len * game->img_height;
	game->win = mlx_new_window(
			game->mlx,
			game->screen_width,
			game->screen_height,
			"so_long");
	if (game->win == NULL)
		print_error(game, "Error: Could not create a window");
	render_game(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, (1 << 17), ft_close, game);
	mlx_loop(game->mlx);
}
