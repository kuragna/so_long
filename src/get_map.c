/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:05:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/22 15:16:17 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_map_size(const char *file_path)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	fd = open(file_path, O_RDONLY);
	if (!fd)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		size += 1;
		free(line);
	}
	close(fd);
	return (size);
}

void	get_map(t_game *game, const char *file_path)
{
	int		fd;
	int		i;

	i = 0;
	game->col_len = get_map_size(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1 || game->col_len <= 0)
		return ;
	game->map = malloc(sizeof(char *) * (game->col_len + 1));
	if (!game->map)
		return ;
	while (i < game->col_len)
	{
		game->map[i] = get_next_line(fd);
		i += 1;
	}
	game->row_len = (ft_strlen(game->map[0]) - 1);
	game->map[i] = NULL;
	close(fd);
}
