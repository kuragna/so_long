/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_screen_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:57:16 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:03:51 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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
