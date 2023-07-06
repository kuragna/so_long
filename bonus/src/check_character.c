/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:00:30 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/06 15:47:27 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	is_char(int c)
{
	if (c == CHAR_E || c == CHAR_C || c == CHAR_P
		|| c == CHAR_N || c == CHAR_0 || c == CHAR_1)
		return (TRUE);
	return (FALSE);
}

int	check_character(t_game *game)
{
	char	*map;
	int		y;

	y = 0;
	while (++y < game->col_len - 1)
	{
		map = game->map[y];
		while (*map && *map != '\n')
		{
			if (!is_char(*map))
				return (FALSE);
			if (*map == CHAR_E)
				game->count[0] += 1;
			else if (*map == CHAR_P)
				game->count[1] += 1;
			else if (*map == CHAR_C)
				game->count[2] += 1;
			map++;
		}
	}
	return (game->count[0] == 1 && game->count[1] == 1 && game->count[2] >= 1);
}
