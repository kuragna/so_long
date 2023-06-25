/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_e_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:00:30 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/25 20:35:29 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_c_e_p(t_game *game)
{
	char	**map;
	int		y;
	int		x;

	y = 0;
	map = game->map;
	while (++y < game->col_len - 1)
	{
		x = 0;
		while (++x < game->row_len)
		{
			if (map[y][x] != 'E' && map[y][x] != 'P' &&
					map[y][x] != 'C' && map[y][x] != '0' && map[y][x] != '1')
				return (1);
			if (map[y][x] == EXIT)
				game->count[0]++;
			else if (map[y][x] == PLAYER)
				game->count[1]++;
			else if (map[y][x] == COLLECT)
				game->count[2]++;
		}
	}
	if (game->count[0] != 1 || game->count[1] != 1 || game->count[2] < 1)
		return (1);
	return (0);
}
