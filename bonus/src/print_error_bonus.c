/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:31:41 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:04:31 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	print_error(char **map, const char *err_msg)
{
	ft_putendl_fd((char *)err_msg, STDERR);
	if (map)
		ft_free(map);
	exit(EXIT_FAILURE);
}
