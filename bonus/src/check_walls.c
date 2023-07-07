/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:50 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/07 18:41:24 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_walls(char **map, int col_len, int row_len)
{
	char	*first;
	char	*last;
	int		i;

	i = 0;
	first = map[0];
	last = map[col_len - 1];
	while ((*first && *first != '\n') && (*last && *last != '\n'))
	{
		if (*first != CHAR_1 || *last != CHAR_1)
			return (FALSE);
		first++;
		last++;
	}
	while (i < col_len)
	{
		if (map[i][0] != CHAR_1
			|| map[i][row_len - 1] != CHAR_1 || map[i][row_len] != '\n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
