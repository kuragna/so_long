/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:31:15 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/07 19:12:41 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	update_player(t_game *game, void **imgs)
{
	const int	y = game->player.pos.y;
	const int	x = game->player.pos.x;
	char		*count;

	if (game->map[y][x] == CHAR_C)
	{
		game->map[y][x] = CHAR_0;
		game->count -= 1;
	}
	put_image(game, game->space, x, y);
	game->count_move += 1;
	count = ft_itoa(game->count_move);
	ft_printf("number of movements : %d\n", game->count_move);
	put_image(game, game->wall, 0, 0);
	put_image(game, imgs[game->player.flag], x, y);
	mlx_string_put(game->mlx, game->win, 5, 1, WHITE, count);
	free(count);
}
