/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:31:15 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:14:14 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_player(t_game *game, void **imgs)
{
	const int	y = game->player.pos.y;
	const int	x = game->player.pos.x;

	if (game->map[y][x] == CHAR_C)
	{
		game->map[y][x] = CHAR_0;
		game->count -= 1;
	}
	put_image(game, game->imgs[SPACE], x, y);
	game->count_move += 1;
	ft_printf("Movements: %d\n", game->count_move);
	put_image(game, imgs[game->player.flag], x, y);
}
