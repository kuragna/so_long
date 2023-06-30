/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:36:52 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/30 14:28:33 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_collectible_path(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == COLLECT)
		*count -= 1;
	map[y][x] = WALL;
	if (map[y][x - 1] != WALL && map[y][x - 1] != EXIT)
		check_collectible_path(map, x - 1, y, count);
	if (map[y + 1][x] != WALL && map[y + 1][x] != EXIT)
		check_collectible_path(map, x, y + 1, count);
	if (map[y][x + 1] != WALL && map[y][x + 1] != EXIT)
		check_collectible_path(map, x + 1, y, count);
	if (map[y - 1][x] != WALL && map[y - 1][x] != EXIT)
		check_collectible_path(map, x, y - 1, count);
}

static void	check_exit_path(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == EXIT)
		*count -= 1;
	map[y][x] = WALL;
	if (map[y][x - 1] != WALL)
		check_exit_path(map, x - 1, y, count);
	if (map[y + 1][x] != WALL)
		check_exit_path(map, x, y + 1, count);
	if (map[y][x + 1] != WALL)
		check_exit_path(map, x + 1, y, count);
	if (map[y - 1][x] != WALL)
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
		return (1);
	check_collectible_path(map, x, y, &count);
	ft_free(map);
	if (count > 0)
		return (1);
	map = map_dup(game->map, game->col_len);
	if (!map)
		return (1);
	count = 1;
	check_exit_path(map, x, y, &count);
	if (count > 0)
		return (1);
	ft_free(map);
	return (0);
}
