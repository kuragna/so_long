/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:36:52 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/02 19:01:27 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	check_collectible_path(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == CHAR_C)
		*count -= 1;
	map[y][x] = CHAR_1;
	if (map[y][x - 1] != CHAR_1 && map[y][x - 1] != CHAR_E)
		check_collectible_path(map, x - 1, y, count);
	if (map[y + 1][x] != CHAR_1 && map[y + 1][x] != CHAR_E)
		check_collectible_path(map, x, y + 1, count);
	if (map[y][x + 1] != CHAR_1 && map[y][x + 1] != CHAR_E)
		check_collectible_path(map, x + 1, y, count);
	if (map[y - 1][x] != CHAR_1 && map[y - 1][x] != CHAR_E)
		check_collectible_path(map, x, y - 1, count);
}

static void	check_exit_path(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == CHAR_E)
		*count -= 1;
	map[y][x] = CHAR_1;
	if (map[y][x - 1] != CHAR_1)
		check_exit_path(map, x - 1, y, count);
	if (map[y + 1][x] != CHAR_1)
		check_exit_path(map, x, y + 1, count);
	if (map[y][x + 1] != CHAR_1)
		check_exit_path(map, x + 1, y, count);
	if (map[y - 1][x] != CHAR_1)
		check_exit_path(map, x, y - 1, count);
}

int	check_path(t_game *game)
{
	const int	x = game->player.pos.x;
	const int	y = game->player.pos.y;
	int			count;
	char		**map;

	count = game->count[2];
	map = map_dup(game->map, game->col_len);
	if (!map)
		return (FALSE);
	check_collectible_path(map, x, y, &count);
	ft_free(map);
	if (count > 0)
		return (FALSE);
	map = map_dup(game->map, game->col_len);
	if (!map)
		return (FALSE);
	count = 1;
	check_exit_path(map, x, y, &count);
	if (count > 0)
		return (FALSE);
	ft_free(map);
	return (TRUE);
}
