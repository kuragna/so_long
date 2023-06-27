/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:53:45 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/27 17:20:33 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**map_dup(char **map, size_t size)
{
	char	**tmp;
	size_t	i;

	i = 0;
	tmp = malloc(sizeof(char *) * (size + 1));
	if (!tmp)
		return (NULL);
	while (map[i])
	{
		tmp[i] = ft_strdup(map[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
