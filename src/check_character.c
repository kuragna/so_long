/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_e_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:00:30 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/02 18:54:16 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_character(t_game *game)
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
				return (FALSE);
			if (map[y][x] == CHAR_E)
				game->count[0]++;
			else if (map[y][x] == CHAR_P)
				game->count[1]++;
			else if (map[y][x] == CHAR_C)
				game->count[2]++;
		}
	}
	if (game->count[0] != 1 || game->count[1] != 1 || game->count[2] < 1)
		return (FALSE);
	return (TRUE);
}
