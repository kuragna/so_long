/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:31:15 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/30 15:39:09 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// TODO: fix render number greather than 99

void	update_player(t_game *game)
{
	char	*count;
	const int	y = game->player.pos.y;
	const int	x = game->player.pos.x;

	if (game->map[y][x] == COLLECT)
	{
		game->map[y][x] = SPACE;
		game->count[2] -= 1;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->wall,
		x * game->img_width, y * game->img_height);
	game->count_move += 1;
	count = ft_itoa(game->count_move);
	printf("number of movements : %d\n", game->count_move);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, 0, 0);
	mlx_string_put(game->mlx, game->win, 5, 1, WHITE, count);
	free(count);
}
