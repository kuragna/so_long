/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:54:13 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/16 16:20:53 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	get_pos(char **map, t_pos *player)
{
	int	y;
	int	x;

	y = 0;
	(void)exit;
	while (map[++y])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == CHAR_P)
			{
				player->x = x;
				player->y = y;
			}
		}
	}
}
