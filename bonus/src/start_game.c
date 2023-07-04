/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:29:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 18:26:01 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	ft_close()
{
	exit(EXIT_SUCCESS);
	return (0);
}

// void	move_player(t_game *game, int x, int y)
// {
// 	update_player(game);
// 	put_image(game, game->space, x, y);
// }

// int	key_hook(int keycode, t_game *game)
// {
// 	t_pos *pos;
// 	
// 	pos = &game->player.pos;
// 	if (game->player.flag == 2)
// 		game->player.flag = 0;

// 	if (keycode == KEY_W && game->map[pos->y - 1][pos->x] != CHAR_1)
// 	{
// 		if (game->map[pos->y - 1][pos->x] == CHAR_E && game->count[2] > 0)
// 			return (1);
// 		put_image(game, game->space, pos->x, pos->y);
// 		pos->y -= 1;
// 		move_player(game, pos->x, pos->y);
// 		put_image(game, game->player.img_up[game->player.flag], pos->x, pos->y);
// 	}
// 	if (keycode == KEY_S && game->map[pos->y + 1][pos->x] != CHAR_1)
// 	{
// 		if (game->map[pos->y + 1][pos->x] == CHAR_E && game->count[2] > 0)
// 			return (1);
// 		put_image(game, game->space, pos->x, pos->y);
// 		pos->y += 1;
// 		move_player(game, pos->x, pos->y);
// 		put_image(game, game->player.img_down[game->player.flag], pos->x, pos->y);
// 	}
// 	if (keycode == KEY_A && game->map[pos->y][pos->x - 1] != CHAR_1)
// 	{
// 		if (game->map[pos->y][pos->x - 1] == CHAR_E && game->count[2] > 0)
// 			return (1);
// 		put_image(game, game->space, pos->x, pos->y);
// 		pos->x -= 1;
// 		move_player(game, pos->x, pos->y);
// 		put_image(game, game->player.img_left[game->player.flag], pos->x, pos->y);
// 	}
// 	if (keycode == KEY_D && game->map[pos->y][pos->x + 1] != CHAR_1)
// 	{
// 		if (game->map[pos->y][pos->x + 1] == CHAR_E && game->count[2] > 0)
// 			return (1);
// 		put_image(game, game->space, pos->x, pos->y);
// 		pos->x += 1;
// 		move_player(game, pos->x, pos->y);
// 		put_image(game, game->player.img_right[game->player.flag], pos->x, pos->y);
// 	}
// 	if (keycode == KEY_ESC)
// 		ft_close();
// 	game->player.flag += 1;
// 	return (0);
// }

int	keypress(int keycode)
{
	printf("keycode: %d\n", keycode);
	return 0;
}


	

int	put_enemy(t_game *game, int flag)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (game->screen_width / game->img_height))
	{
		x = -1;
		while (++x < (game->screen_width / game->img_width))
		{
			if (game->map[y][x] == CHAR_N)
			{
				mlx_put_image_to_window(
					game->mlx, game->win,
					game->enemy.imgs[flag],
					x * game->img_width,
					y * game->img_height);
			}
		}
	}
	return 0;
}

int	animation(t_game *game)
{
	if (game->enemy.count == 2500)
	{
		if (game->enemy.flag == 4)
			game->enemy.flag = 0;
		put_enemy(game, game->enemy.flag);
		game->enemy.flag += 1;
		game->enemy.count = 0;
	}
	game->enemy.count += 1;
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
	mlx_loop_hook(game->mlx, animation, game);
	mlx_key_hook(game->win, keypress, game);
	mlx_hook(game->win, 17, (1 << 17), ft_close, game);
	mlx_loop(game->mlx);
}
