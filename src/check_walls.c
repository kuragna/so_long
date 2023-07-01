/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:50 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/30 19:27:51 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_walls(t_game *game)
{
	char	*first;
	char	*last;
	int		i;

	if (game->col_len == game->row_len)
		return (1);
	first = game->map[0];
	last = game->map[game->col_len - 1];
	while ((*first && *first != '\n') && (*last && *last != '\n'))
	{
		if (*first != CHAR_1 || *last != CHAR_1)
			return (1);
		first++;
		last++;
	}
	i = 0;
	while (++i < game->col_len - 1)
	{
		if (game->map[i][0] != CHAR_1 ||
			game->map[i][game->row_len - 1] != CHAR_1)
			return (1);
	}
	return (0);
}
