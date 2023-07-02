/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/02 20:30:20 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <time.h>

void	free_game(t_game *game);
int	animate_enemy(t_game *game);
void	fill_screen(t_game *game, int color);
int end_game(t_game *game);

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

void	find_leaks()
{
	system("leaks -q so_long");
}

t_game *game_init()
{
	t_game *game;
	size_t	size;

	size = sizeof(*game);
	game = malloc(size);
	ft_memset(game, 0, size);
	return (game);
}

void	print_error(t_game *game, const char *err_msg)
{
	ft_putendl_fd((char*)err_msg, STDERR);
	free_game(game);
	exit(EXIT_FAILURE);
}

int	move_enemy(t_game *game)
{
	const int img_width = game->img_width;
	const int img_height = game->img_height;


	int x = game->player.pos.x;
	int y = game->player.pos.y;

	printf("x: %d | y: %d\n", x, y);

	mlx_put_image_to_window(game->mlx, game->win, game->space,
			(abs(x) * img_width), y * img_height);
	game->player.pos.x += 1;
	x = game->player.pos.x;
// 	mlx_put_image_to_window(game->mlx, game->win, game->player.img[2],
// 			(abs(x) * img_width), (y * img_height));
	return 0;	
}



void	start_game(t_game *game)
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
	render_game(game);
	mlx_hook(game->win, 17, (1 << 17), close_win, game);
	mlx_loop_hook(game->mlx, end_game, game);
	mlx_loop(game->mlx);
}

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

int		end_game(t_game *game)
{
	const int x = game->player.pos.x;
	const int y = game->player.pos.y;

	if (game->count[2] == 0 && game->map[y][x] == CHAR_E)
	{
		fill_screen(game, DARK);
		mlx_string_put(game->mlx, game->win, (game->screen_width / 2),
			game->screen_height / 2, WHITE, "The end");
	}
	return 0;
}

void	fill_screen(t_game *game, int color)
{
	for (int y = 0; y < game->screen_height; y++)
	{
		for (int x = 0; x < game->screen_width; x++)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, color);
		}
	}
}

int	ft_close(int keycode)
{
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return 0;
}


// int	animate_enemy(t_game *game)
// {
// 	int x = game->player.pos.x;
// 	int y = game->player.pos.y;

// 	if (game->map[y][x - 1] == CHAR_1)
// 	{
// 		game->player.pos.x *= -1;
// 	}
// 	if (count == 2500)
// 	{
// 		if (idx == 3)
// 			idx = 0;
// 		mlx_put_image_to_window(game->mlx, game->win, game->space,
// 				abs(x) * game->img_width, y * game->img_height);
// 		game->player.pos.x -= 1;
// 		x = game->player.pos.x;
// 		mlx_put_image_to_window(game->mlx, game->win, game->player.img[idx],
// 				abs(x) * game->img_width, y * game->img_height);
// 		count = 0;
// 		idx += 1;
// 	}
// 	count += 1;
// 	return 0;
// }


#if 0
int	main(void)
{
	t_game *game = game_init();

	game->mlx = mlx_init();

	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "So_long");

	fill_screen(game, DARK);

	game->space = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm",
			&game->player.img_width, &game->player.img_height);
	game->player.img[0] = mlx_xpm_file_to_image(game->mlx, "./texturesEfire_1.xpm",
			&game->player.img_width, &game->player.img_height);
	game->player.img[1] = mlx_xpm_file_to_image(game->mlx, "./textures/fire_2.xpm",
			&game->player.img_width, &game->player.img_height);
	game->player.img[2] = mlx_xpm_file_to_image(game->mlx, "./textures/fire_3.xpm",
			&game->player.img_width, &game->player.img_height);
	game->player.img[3] = mlx_xpm_file_to_image(game->mlx, "./textures/fire_4.xpm",
			&game->player.img_width, &game->player.img_height);


	mlx_do_sync(game->mlx);
	mlx_put_image_to_window(game->mlx, game->win, game->player.img[0],
			SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	mlx_loop_hook(game->mlx, animate_enemy, game);

	mlx_loop(game->mlx);
	return 0;
}
#endif

int	main(int argc, char **argv)
{
// 	atexit(find_leaks);
	t_game	*game;
	char	*file_path;

	file_path = argv[1];
	if (argc != 2 || !check_file_path(file_path))
	{
		ft_putendl_fd("usage: so_long/file_name.ber", STDERR);
		return (1);
	}
	game = game_init();
	if (!get_map(game, file_path))
	{
		print_error(game, "Error: Could not read the map");
	}
	if (game->map[0] == NULL || !check_walls(game))
	{
		print_error(game, "Error: The map has invalid wall");
	}
	if (!check_character(game))
	{
		print_error(game, "Error: The map has wrong character");
	}
	get_pos(game);
	if (!check_path(game))
	{
		print_error(game, "Error: The map has invalid path");
	}
	start_game(game);
	return (0);
}
