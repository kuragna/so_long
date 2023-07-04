/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:29:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 17:46:20 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_close()
{
	exit(EXIT_SUCCESS);
	return (0);
}

void	move_player(t_game *game, int x, int y)
{
	update_player(game);
	put_image(game, game->space, x, y);
}

int	key_hook(int keycode, t_game *game)
{
	t_pos *pos;
	
	pos = &game->player.pos;
	if (game->player.flag == 2)
		game->player.flag = 0;

	if (keycode == KEY_W && game->map[pos->y - 1][pos->x] != CHAR_1)
	{
		if (game->map[pos->y - 1][pos->x] == CHAR_E && game->count[2] > 0)
			return (1);
		put_image(game, game->space, pos->x, pos->y);
		pos->y -= 1;
		move_player(game, pos->x, pos->y);
		put_image(game, game->player.img_up[game->player.flag], pos->x, pos->y);
	}
	if (keycode == KEY_S && game->map[pos->y + 1][pos->x] != CHAR_1)
	{
		if (game->map[pos->y + 1][pos->x] == CHAR_E && game->count[2] > 0)
			return (1);
		put_image(game, game->space, pos->x, pos->y);
		pos->y += 1;
		move_player(game, pos->x, pos->y);
		put_image(game, game->player.img_down[game->player.flag], pos->x, pos->y);
	}
	if (keycode == KEY_A && game->map[pos->y][pos->x - 1] != CHAR_1)
	{
		if (game->map[pos->y][pos->x - 1] == CHAR_E && game->count[2] > 0)
			return (1);
		put_image(game, game->space, pos->x, pos->y);
		pos->x -= 1;
		move_player(game, pos->x, pos->y);
		put_image(game, game->player.img_left[game->player.flag], pos->x, pos->y);
	}
	if (keycode == KEY_D && game->map[pos->y][pos->x + 1] != CHAR_1)
	{
		if (game->map[pos->y][pos->x + 1] == CHAR_E && game->count[2] > 0)
			return (1);
		put_image(game, game->space, pos->x, pos->y);
		pos->x += 1;
		move_player(game, pos->x, pos->y);
		put_image(game, game->player.img_right[game->player.flag], pos->x, pos->y);
	}
	if (keycode == KEY_ESC)
		ft_close();
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
	render_game(game);
	if (game->win == NULL)
		print_error(game, "Error: Could not create a window");
// 	put_image(game, game->enemy.imgs[0], 2, 2);
// 	mlx_loop_hook(game->mlx, animate_enemy, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, (1 << 17), ft_close, game);
	mlx_loop(game->mlx);
}
