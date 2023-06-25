/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/25 14:34:28 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, void *param);

/*
 *	TODO: File name with .ber extension.- DONE
 *	TODO: Valid file path. - DONE
 *	TODO: The map has 1 exit, 1 player and at least 1 collectible. - DONE
 *	TODO: The map must be rectangular. - DONE
 *	TODO: The map must be closed/surrounded by walls. - DONE
 *	TODO: Valid player path to exit.
 *
 * */

// initialise
// do
//      input
//      update
//      render
// loop
// clean up

#define BTN_LEFT 1
#define EXTENSION ".ber"

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

void	get_pos(t_game *game)
{
	int	y;

	y = 0;
	while (++y < game->col_len - 1)
	{
		int	x = 0;
		while (++x < game->row_len)
		{
			if (game->map[y][x] == 'P')
			{
				game->player.position.x = x;
				game->player.position.y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit_pos.x = x;
				game->exit_pos.y = y;
			}
		}
	}
}

#define PUT_IMAGE(img) mlx_put_image_to_window(game->mlx, game->win, img, img_width * x, img_height * y)

void	render_game(t_game *game)
{
	int	img_width = game->img_width;
	int	img_height = game->img_height;
	size_t	width = (game->screen_width / img_width);
	size_t	height = (game->screen_height / img_height);
	size_t	y = -1;
	size_t	x;

	while (++y < height)
	{
		x = -1;
		while (++x < width)
		{
			if (game->map[y][x] == '1')
				PUT_IMAGE(game->wall);
			if (game->map[y][x] != '1')
				PUT_IMAGE(game->space);
			if (game->map[y][x] == 'P')
				PUT_IMAGE(game->wall);
			if (game->map[y][x] == 'C')
				PUT_IMAGE(game->collectible);
			if (game->map[y][x] == 'E')
				PUT_IMAGE(game->exit);
		}	
	}
}

void	update_player(t_game *game)
{
	char	*count;
	int		x;
	int		y;

	x = game->player.position.x;
	y = game->player.position.y;

	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->count[2] -= 1;
	}

	printf("collectible count: %d\n", game->count[2]);
	printf("-------------------------------\n");

	mlx_put_image_to_window(game->mlx, game->win, game->wall, 
			x * game->img_width, y * game->img_height);
	game->count_move += 1;
	count = ft_itoa(game->count_move);
	mlx_string_put(game->mlx, game->win, (game->screen_width / 2), 1, WHITE, count);
	free(count);
	printf("number of movements : %d\n", game->count_move);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	(void)x;

	if (button == BTN_LEFT && y < 0)
	{
		if (x >= 10 && x <= 20)
			exit(0);
	}
	return (0);
}

int	key_hook(int keycode, void *param)
{
	/*
	 *	W = UP 		-> player[y - 1][x]
	 *	S = DOWN	-> player[y + 1][x]
	 *	A = LEFT	-> player[y][x - 1]
	 *	D = RIGHT	-> player[y][x + 1]
	 * */

	t_game *game = (t_game*)param;
	int	y = game->player.position.y;
	int	x = game->player.position.x;

	if (keycode == W && game->map[y - 1][x] != '1') // UP
	{
		if (game->map[y - 1][x] == 'E' && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.y -= 1;
		update_player(game);
	}
	if (keycode == S && game->map[y + 1][x] != '1') // DOWN
	{
		if (game->map[y + 1][x] == 'E' && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.y += 1;
		update_player(game);
	}
	if (keycode == A && game->map[y][x - 1] != '1') // LEFT
	{
		if (game->map[y][x - 1] == 'E' && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.x -= 1;
		update_player(game);
	}
	if (keycode == D && game->map[y][x + 1] != '1') // RIGHT
	{
		if (game->map[y][x + 1] == 'E' && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.x += 1;
		update_player(game);
	}
	if (keycode == ESC)
		exit(0);
	return 0;
}

void	get_images(t_game *game)
{

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

void	check_path(char **map, int x, int y)
{
	printf("------------------\n");
	print_map(map);
	if (map[y][x - 1] == 'E' || map[y][x + 1] == 'E'
	   || map[y - 1][x] == 'E' || map[y + 1][x] == 'E')
	{
		printf("Player can access to exit\n");
		return ;
	}
	else
	{
		map[y][x] = '1';
		if (map[y][x - 1] == '0')
			check_path(map, x - 1, y);
		if (map[y + 1][x] == '0')
			check_path(map, x, y + 1);
		if (map[y][x + 1] == '0')
			check_path(map, x + 1, y);
		if (map[y - 1][x] == '0')
			check_path(map, x, y - 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;

	t_game *game = game_init();

	get_map(game, argv[1]);
	
	print_map(game->map);

	get_pos(game);

	t_vector player = game->player.position;
	t_vector exit = game->exit_pos;
	printf("player(%d, %d)\n", player.x, player.y);
	printf("exit(%d, %d)\n", exit.x, exit.y);

	int	size = 0;
	printf("size: %d\n", size);
	check_path(game->map, player.x, player.y);

	return 0;
}

int	main2(int argc, char **argv)
{
// 	atexit(find_leaks);

	const char	*file_path = argv[1];
	t_game	*game;

	if (argc != 2 || check_file_path(file_path))
	{
		printf("usage: so_long maps/file_name.ber\n");
		return (1);
	}

	game = game_init();
	game->mlx = mlx_init();
	get_map(game, file_path);
	if (game->map == NULL)
	{
		printf("Error: could not read a file\n");
		return (1);
	}

	if (game->map[0] == NULL || check_walls(game))
	{
		printf("Error: invalid walls\n");
		return (1);
	}

	if (check_c_e_p(game))
	{
		printf("Error: invalid player, exit or collectible\n");
		return (1);
	}

	print_map(game->map);
	get_pos(game);



// 	int err = check_path(game->map, 
// 			game->player.position.x, 
// 			game->player.position.y);
// 	printf("err: %d\n", err);

	return 0;

	get_images(game);

	game->screen_width = game->row_len * game->img_width;
	game->screen_height = game->col_len * game->img_height;


	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "so_long");


	mlx_key_hook(game->win, key_hook, game);

	mlx_mouse_hook(game->win, mouse_hook, game);

	print_map(game->map);
	render_game(game);
	
	get_pos(game);

	mlx_loop(game->mlx);

	return (0);
}

