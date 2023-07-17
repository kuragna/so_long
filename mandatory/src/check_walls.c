/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:50 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/16 14:16:19 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	check_walls(char **map, int col_len, int row_len)
{
	char	*f_line;
	char	*l_line;
	int		i;

	i = 0;
	f_line = map[0];
	l_line = map[col_len - 1];
	while ((*f_line && *f_line != '\n') && (*l_line && *l_line != '\n'))
	{
		if (*f_line != CHAR_1 || *l_line != CHAR_1)
			return (FALSE);
		f_line += 1;
		l_line += 1;
	}
	while (map[i] != NULL)
	{
		if (map[i][0] != CHAR_1
			|| (map[i][row_len] != '\n' && map[i][row_len])
			|| map[i][row_len - 1] != CHAR_1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
/* if (map[i][0] != CHAR_1)
	return (FALSE);
    if (map[i][row_len] != '\n' && map[i][row_len])
			return (FALSE);
		if (map[i][row_len - 1] != CHAR_1)
			return (FALSE); */