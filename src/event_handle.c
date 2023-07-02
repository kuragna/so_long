/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:28:53 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/02 20:31:49 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	y = game->player.pos.y;
	int	x = game->player.pos.x;

	if (game->player.flag == 2)
		game->player.flag = 0;

	if (keycode == KEY_W && game->map[y - 1][x] != CHAR_1)
	{
		if (game->map[y - 1][x] == CHAR_E && game->count[2] > 0)
			return (1);
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			x * game->img_width, y * game->img_height);
		game->player.pos.y -= 1;
		update_player(game);
		y = game->player.pos.y;
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			x * game->img_width, y * game->img_height);
		mlx_put_image_to_window(game->mlx, game->win, 
			game->player.player_up[game->player.flag],
			x * game->img_width, y * game->img_height);
	}
	if (keycode == KEY_S && game->map[y + 1][x] != CHAR_1)
	{
		if (game->map[y + 1][x] == CHAR_E && game->count[2] > 0)
			return (1);
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			x * game->img_width, y * game->img_height);
		game->player.pos.y += 1;
		update_player(game);
		y = game->player.pos.y;
		mlx_put_image_to_window(game->mlx, game->win, 
			game->player.player_down[game->player.flag],
			x * game->img_width, y * game->img_height);
	}
	if (keycode == KEY_A && game->map[y][x - 1] != CHAR_1)
	{
		if (game->map[y][x - 1] == CHAR_E && game->count[2] > 0)
			return (1);
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			x * game->img_width, y * game->img_height);
		game->player.pos.x -= 1;
		update_player(game);
		x = game->player.pos.x;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_left[game->player.flag],
			x * game->img_width, y * game->img_height);
	}
	if (keycode == KEY_D && game->map[y][x + 1] != CHAR_1)
	{
		if (game->map[y][x + 1] == CHAR_E && game->count[2] > 0)
			return (1);
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			x * game->img_width, y * game->img_height);
		game->player.pos.x += 1;
		update_player(game);
		x = game->player.pos.x;
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_right[game->player.flag],
			x * game->img_width, y * game->img_height);
	}
	game->player.flag += 1;
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	return (0);
}
