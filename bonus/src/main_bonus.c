/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/17 19:04:20 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(
		game->mlx,
		game->win,
		img,
		x * game->img_width,
		y * game->img_height);
}

int	main(int argc, char **argv)
{
	const char	*file_path = argv[1];
	t_game		game;

	if (argc != 2 || !check_file_path(file_path))
	{
		ft_putendl_fd("usage: so_long/file_name.ber", STDERR);
		return (1);
	}
	ft_bzero(&game, sizeof(game));
	if (!get_map(&game, file_path))
		print_error(game.map, "Error: Could not read the map");
	if (!check_walls(game.map, game.col_len, game.row_len))
		print_error(game.map, "Error: The map has invalid wall");
	if (!check_character(game.map, &game.count))
		print_error(game.map, "Error: The map has wrong character");
	get_pos(game.map, &game.player.pos);
	if (!check_player_path(&game))
		print_error(game.map, "Error: The map has invalid path");
	start_game(&game);
	return (0);
}
