/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_path_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:31 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:03:21 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	check_file_path(const char *file_path)
{
	if (ft_strnstr(file_path, "maps", ft_strlen(file_path)))
	{
		file_path = ft_strrchr(file_path, '.');
		if (file_path == NULL || ft_strncmp(file_path, ".ber", 4) == 0)
			return (TRUE);
	}
	return (FALSE);
}
