/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:29:04 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/06 19:24:24 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	finish_game(t_game *game);

static int	ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

// void	move_player(t_game *game, void **imgs)
// {
// 	const t_pos	pos = game->player.pos;

// 	update_player(game);
// 	put_image(game, game->space, pos.x, pos.y);
// 	put_image(game, imgs[game->player.flag], pos.x, pos.y);
// }

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
	}
	if (keycode == KEY_S && game->map[pos->y + 1][pos->x] != CHAR_1)
	{
		if (game->map[pos->y + 1][pos->x] == CHAR_E && game->count[2] > 0)
			return ;
		put_image(game, game->space, pos->x, pos->y);
		pos->y += 1;
		update_player(game, game->player.imgs_down);
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
	}
	if (keycode == KEY_D && game->map[pos->y][pos->x + 1] != CHAR_1)
	{
		if (game->map[pos->y][pos->x + 1] == CHAR_E && game->count[2] > 0)
			return ;
		put_image(game, game->space, pos->x, pos->y);
		pos->x += 1;
		update_player(game, game->player.imgs_right);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (game->map[game->player.pos.y][game->player.pos.x] == CHAR_N)
		game->end = TRUE;
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
	game->screen_width = (game->row_len * game->img_width);
	game->screen_height = (game->col_len * game->img_height);
	game->win = mlx_new_window(
			game->mlx,
			game->screen_width,
			game->screen_height,
			"so_long");
	render_game(game);
	if (game->win == NULL)
		print_error(game, "Error: Could not create a window");
	mlx_loop_hook(game->mlx, animate_enemy, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, (1 << 17), ft_close, game);
	mlx_loop(game->mlx);
}
