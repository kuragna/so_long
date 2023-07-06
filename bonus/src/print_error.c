/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:31:41 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/06 20:02:20 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// TODO: test memory leaks after call exit()
void	print_error(t_game *game, const char *err_msg)
{
	ft_putendl_fd((char *)err_msg, STDERR);
	if (game->col_len > 0)
		ft_free(game->map);
	if (game)
		free(game);
	exit(EXIT_FAILURE);
}
