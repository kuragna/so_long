/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:53:26 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/26 17:53:37 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(t_game *game)
{
	if (game->map != NULL)
		ft_free(game->map);
	game->map = NULL;
	if (game != NULL)
		free(game);
	game = NULL;
}
