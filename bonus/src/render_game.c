/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:11 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 17:53:07 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
			put_image(game, game->space, x, y);
			if (game->map[y][x] == CHAR_1)
				put_image(game, game->wall, x, y);
			if (game->map[y][x] == CHAR_C)
				put_image(game, game->collectible, x, y);
			if (game->map[y][x] == CHAR_N)
				put_image(game, game->enemy.imgs[0], x, y);
		}
	}
	put_image(game, game->player.img_up[0],
		game->player.pos.x, game->player.pos.y);
	put_image(game, game->exit, game->exit_pos.x, game->exit_pos.y);
}
