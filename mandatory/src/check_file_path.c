/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:18:31 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/02 18:59:00 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
