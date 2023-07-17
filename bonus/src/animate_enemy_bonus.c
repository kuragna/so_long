/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:25:19 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:03:10 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

static void	update_enemy(t_game *game, int flag)
{
	int	y;
	int	x;

	y = 0;
	while (y < (game->screen_height / game->img_height))
	{
		x = 0;
		while (x < (game->screen_width / game->img_width))
		{
			if (game->map[y][x] == CHAR_N)
			{
				put_image(game, game->enemy.imgs[flag], x, y);
			}
			x++;
		}
		y++;
	}
}

int	animate_enemy(t_game *game)
{
	if (game->end == TRUE)
		return (0);
	if (game->enemy.count == 2500)
	{
		if (game->enemy.flag == 4)
			game->enemy.flag = 0;
		update_enemy(game, game->enemy.flag);
		game->enemy.flag += 1;
		game->enemy.count = 0;
	}
	game->enemy.count += 1;
	return (0);
}
