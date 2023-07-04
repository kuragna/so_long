/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_e_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:00:30 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 18:37:36 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	is_char(int c)
{
	if (c == CHAR_E || c == CHAR_C || c == CHAR_P
		|| c == CHAR_0 || c == CHAR_1)
		return (TRUE);
	return (FALSE);
}

int	check_character(t_game *game)
{
	char	*line;
	int		y;

	y = 0;
	while (++y < game->col_len - 1)
	{
		line = game->map[y];
		while (*line && *line != '\n')
		{
			if (!is_char(*line))
				return (FALSE);
			if (*line == CHAR_E)
				game->count[0]++;
			else if (*line == CHAR_P)
				game->count[1]++;
			else if (*line == CHAR_C)
				game->count[2]++;
			line++;
		}
	}
	return (game->count[0] == 1 && game->count[1] == 1 && game->count[2] >= 1);
}
