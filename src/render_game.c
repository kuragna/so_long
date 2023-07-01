/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:11 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/01 14:52:40 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_exit_player(t_game *game)
{
	mlx_put_image_to_window(
		game->mlx,
		game->win,
		game->player.img[2],
		game->player.pos.x * game->img_width,
		game->player.pos.y * game->img_height);
	mlx_put_image_to_window(
		game->mlx,
		game->win,
		game->exit,
		game->exit_pos.x * game->img_width,
		game->exit_pos.y * game->img_height);
}

void	render_game(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (game->screen_height / game->img_height))
	{
		x = -1;
		while (++x < (game->screen_width / game->img_width))
		{
			if (game->map[y][x] == CHAR_1)
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall, game->img_width * x, game->img_height * y);
			if (game->map[y][x] != CHAR_1)
				mlx_put_image_to_window(game->mlx, game->win,
					game->space, game->img_width * x, game->img_height * y);
			if (game->map[y][x] == CHAR_C)
				mlx_put_image_to_window(game->mlx, game->win,
					game->collectible,
					game->img_width * x, game->img_height * y);
		}	
	}
	render_exit_player(game);
}
