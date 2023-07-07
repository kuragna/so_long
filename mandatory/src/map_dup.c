/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:53:45 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/07 13:03:24 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
		if (!tmp[i])
			return (NULL);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
