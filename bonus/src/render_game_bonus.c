/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:33:11 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:04:38 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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
			if (game->map[y][x] != CHAR_1)
				put_image(game, game->imgs[SPACE], x, y);
			if (game->map[y][x] == CHAR_1)
				put_image(game, game->imgs[WALL], x, y);
			if (game->map[y][x] == CHAR_C)
				put_image(game, game->imgs[COLLECTIBLE], x, y);
			if (game->map[y][x] == CHAR_N)
				put_image(game, game->enemy.imgs[0], x, y);
			if (game->map[y][x] == CHAR_E)
				put_image(game, game->imgs[EXIT], x, y);
		}
	}
	put_image(game, game->player.imgs_up[0],
		game->player.pos.x, game->player.pos.y);
}
