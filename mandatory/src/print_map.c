/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:19:09 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/22 15:20:19 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	print_map(char	**lines)
{
	int	y;
	int	x;

	y = 0;
	while (lines[y])
	{
		x = 0;
		while (lines[y][x])
		{
			printf("%c", lines[y][x]);
			x++;
		}
		y++;
	}
}