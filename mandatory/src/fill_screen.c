/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:55:23 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/11 13:56:30 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	fill_screen(t_game *game, const char *str)
{
	const int	width = game->screen_width;
	const int	height = game->screen_height;
	int			y;
	int			x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, DARK);
			x++;
		}
		y++;
	}
	game->end = TRUE;
	mlx_string_put(game->mlx, game->win, width / 2, height / 2, WHITE,
		(char *)str);
}
