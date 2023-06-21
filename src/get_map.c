/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:05:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/18 18:14:02 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_map_size(char *file_path)
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

char	**get_map(char *file_path, int *size)
{
	char	**map;
	int		fd;
// 	int		size;
	int		i;

	i = 0;
	*size = get_map_size(file_path);
	fd = open(file_path, O_RDONLY);
	if (fd == -1 || *size == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (*size + 1));
	if (!map)
		return (NULL);
	while (i < *size)
	{
		map[i] = get_next_line(fd);
		i += 1;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
