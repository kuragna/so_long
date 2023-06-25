/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:31 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/22 15:18:32 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_file_path(const char *file_path)
{
	if (ft_strncmp(file_path, "maps/", 5) == 0)
	{
		file_path = ft_strrchr(file_path, '.');
		if (file_path == NULL || ft_strncmp(file_path, ".ber", 4) == 0)
			return (0);
	}
	return (1);
}
