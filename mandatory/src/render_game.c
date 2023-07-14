/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:11 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/14 14:07:19 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	render_game(t_game *game)
{
	const t_pos	pos = game->player.pos;
	int			y;
	int			x;

	y = -1;
	while (++y < (game->screen_height / game->img_height))
	{
		x = -1;
		while (++x < (game->screen_width / game->img_width))
		{
			if (game->map[y][x] != CHAR_1)
				put_image(game, game->space, x, y);
			if (game->map[y][x] == CHAR_1)
				put_image(game, game->wall, x, y);
			if (game->map[y][x] == CHAR_C)
				put_image(game, game->collectible, x, y);
			if (game->map[y][x] == CHAR_N)
				put_image(game, game->enemy.imgs[0], x, y);
		}	
	}
	put_image(game, game->player.imgs_up[0], pos.x, pos.y);
	put_image(game, game->exit, game->exit_pos.x, game->exit_pos.y);
}
