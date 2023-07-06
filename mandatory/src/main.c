/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/06 19:58:15 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

// DONE: empty line before map
// DONE: The map must be rectangular.
// TODO: finish the map if player cross to exit and collectible is 0
// TODO: check file map if doesnt have permision

void	find_leaks(void)
{
	//system("leaks -q so_long");
}

t_game	*game_init(void)
{
	t_game	*game;
	size_t	size;

	size = sizeof(*game);
	game = malloc(size);
	if (game == NULL)
		exit(EXIT_FAILURE);
	ft_memset(game, 0, size);
	return (game);
}

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
	atexit(find_leaks);
	const char	*file_path = argv[1];
	t_game		*game;

	if (argc != 2 || !check_file_path(file_path))
	{
		ft_putendl_fd("usage: so_long/file_name.ber", STDERR);
		return (1);
	}
	game = game_init();
	if (!get_map(game, file_path))
		print_error(game, "Error: Could not read the map");
	if (game->map[0] == NULL || !check_walls(game))
		print_error(game, "Error: The map has invalid wall");
	if (!check_character(game))
		print_error(game, "Error: The map has wrong character");
	get_pos(game->map, &game->player.pos, &game->exit_pos);
	if (!check_path(game))
		print_error(game, "Error: The map has invalid path");
	start_game(game);
	return (0);
}
