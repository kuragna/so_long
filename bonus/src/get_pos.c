/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:54:13 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 13:27:43 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	get_pos(char **map, t_pos *player, t_pos *exit)
{
	int	y;
	int	x;

	y = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == CHAR_P)
			{
				player->x = x;
				player->y = y;
			}
			if (map[y][x] == CHAR_E)
			{
				exit->x = x;
				exit->y = y;
			}
		}
	}
}
// void	get_pos(t_game *game)
// {
// 	int	y;
// 	int	x;

// 	y = 0;
// 	while (++y < game->col_len - 1)
// 	{
// 		x = 0;
// 		while (++x < game->row_len)
// 		{
// 			if (game->map[y][x] == CHAR_P)
// 			{
// 				game->player.pos.x = x;
// 				game->player.pos.y = y;
// 			}
// 			else if (game->map[y][x] == CHAR_E)
// 			{
// 				game->exit_pos.x = x;
// 				game->exit_pos.y = y;
// 			}
// 		}
// 	}
// }
