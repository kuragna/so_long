/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:34:45 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 18:20:50 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	animate_enemy(t_game *game)
{
	if (game->enemy.count == 2500)
	{
		if (game->enemy.flag == 4)
			game->enemy.flag = 0;
		game->enemy.flag += 1;
		game->enemy.count = 0;
	}
	game->enemy.count += 1;
	return (0);
}
