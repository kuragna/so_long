/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/01 15:15:11 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_game(t_game *game);

/*
 *	TODO: File name with .ber extension.- DONE
 *	TODO: Valid file path. - DONE
 *	TODO: The map has 1 exit, 1 player and at least 1 collectible. - DONE
 *	TODO: The map must be rectangular. - DONE
 *	TODO: The map must be closed/surrounded by walls. - DONE
 *	TODO: Valid player path to exit.
 *	TODO: print number of movements in shell and screen. - DONE
 *
 * */

// initialise
// do
//      input
//      update
//      render
// loop
// clean up


void	find_leaks()
{
	system("leaks -q so_long");
}

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting vector

t_game *game_init()
{
	t_game *game;
	size_t	size;

	size = sizeof(*game);
	game = malloc(size);
	ft_memset(game, 0, size);
	return (game);
}

void	get_player_images(t_game *game)
{
		
	game->player.img[0] = mlx_xpm_file_to_image(game->mlx, "./textures/player_up.xpm",
			&game->img_width, &game->img_height);
	game->player.img[1] = mlx_xpm_file_to_image(game->mlx, "./textures/player_down.xpm",
			&game->img_width, &game->img_height);
	game->player.img[2] = mlx_xpm_file_to_image(game->mlx, "./textures/player_left.xpm",
			&game->img_width, &game->img_height);
	game->player.img[3] = mlx_xpm_file_to_image(game->mlx, "./textures/player_right.xpm",
			&game->img_width, &game->img_height);
}

void	get_images(t_game *game)
{
	get_player_images(game);
	game->space = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm",
			&game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->img_width, &game->img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./textures/Cherry.xpm",
			&game->img_width, &game->img_height);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "./textures/fire.xpm",
			&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->img_width, &game->img_height);
}

void	print_error(t_game *game, const char *err_msg)
{
	ft_putendl_fd((char*)err_msg, STDERR);
	free_game(game);
	exit(EXIT_FAILURE);
}


void	so_long_load(t_game *game)
{	
	// TODO: check if mlx function failed
	game->mlx = mlx_init();
	get_images(game);
	game->screen_width = game->row_len * game->img_width;
	game->screen_height = game->col_len * game->img_height;

	game->win = mlx_new_window(
			game->mlx,
			game->screen_width,
			game->screen_height,
			"so_long");

	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, (1 << 17), close_win, game);

	render_game(game);
	mlx_loop(game->mlx);
}


int	main(int argc, char **argv)
{
	atexit(find_leaks);
	t_game	*game;
	char	*file_path;

	file_path = argv[1];
	if (argc != 2 || check_file_path(file_path))
	{
		ft_putendl_fd("usage: so_long/file_name.ber", STDERR);
		return (1);
	}
	game = game_init();
	if (get_map(game, file_path))
	{
		print_error(game, "Error: Could not read the map");
	}
	if (game->map[0] == NULL || check_walls(game))
	{
		print_error(game, "Error: The map has invalid wall");
	}
	if (check_character(game))
	{
		print_error(game, "Error: The map has wrong character");
	}
	get_pos(game);
	if (check_path(game))
	{
		print_error(game, "Error: The map has invalid path");
	}
	so_long_load(game);
	return (0);
}

