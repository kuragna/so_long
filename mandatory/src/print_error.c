/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:31:41 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 17:36:53 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// TODO: test memory leaks after call exit()
void	print_error(t_game *game, const char *err_msg)
{
	(void)game;
	ft_putendl_fd((char *)err_msg, STDERR);
	exit(EXIT_FAILURE);
}
