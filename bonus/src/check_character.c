/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:00:30 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/07 19:41:31 by aabourri         ###   ########.fr       */
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

int	check_character(char **map, int *count)
{
	char	*line;
	int		count_;
	int		y;

	y = 0;
	count_ = 0;
	while (map[++y])
	{
		line = map[y];
		while (*line && *line != '\n')
		{
			if (!is_char(*line))
				return (FALSE);
			if (*line == CHAR_E || *line == CHAR_P)
				count_ += 1;
			else if (*line == CHAR_C)
				*count += 1;
			line++;
		}
	}
	return (*count >= 1 && count_ == 2);
}
