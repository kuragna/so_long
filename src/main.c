/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/27 14:29:30 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int keycode, void *param);
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

void	get_pos(t_game *game)
{
	int	y;

	y = 0;
	while (++y < game->col_len - 1)
	{
		int	x = 0;
		while (++x < game->row_len)
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player.position.x = x;
				game->player.position.y = y;
			}
			else if (game->map[y][x] == EXIT)
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
			if (game->map[y][x] == WALL)
				PUT_IMAGE(game->wall);
			if (game->map[y][x] != WALL)
				PUT_IMAGE(game->space);
			if (game->map[y][x] == PLAYER)
				PUT_IMAGE(game->wall);
			if (game->map[y][x] == COLLECT)
				PUT_IMAGE(game->collectible);
			if (game->map[y][x] == EXIT)
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

	if (game->map[y][x] == COLLECT)
	{
		game->map[y][x] = SPACE;
		game->count[2] -= 1;
	}

	mlx_put_image_to_window(game->mlx, game->win, game->wall,
			x * game->img_width, y * game->img_height);

	game->count_move += 1;
	count = ft_itoa(game->count_move);
	printf("number of movements : %d\n", game->count_move);
	mlx_put_image_to_window(game->mlx, game->win, game->wall, 0, 0);
	// TODO: fix render number greather than 99
	mlx_string_put(game->mlx, game->win, 5, 1, WHITE, count);
	free(count);
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
	t_game	*game;
	int		y;
	int		x;

	game = (t_game*)param;
	y = game->player.position.y;
	x = game->player.position.x;
	if (keycode == UP && game->map[y - 1][x] != WALL) // UP
	{
		if (game->map[y - 1][x] == EXIT && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.y -= 1;
		update_player(game);
	}
	if (keycode == DOWN && game->map[y + 1][x] != WALL) // DOWN
	{
		if (game->map[y + 1][x] == EXIT && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.y += 1;
		update_player(game);
	}
	if (keycode == LEFT && game->map[y][x - 1] != WALL) // LEFT
	{
		if (game->map[y][x - 1] == EXIT  && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.x -= 1;
		update_player(game);
	}
	if (keycode == RIGHT && game->map[y][x + 1] != WALL) // RIGHT
	{
		if (game->map[y][x + 1] == EXIT && game->count[2] > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.x += 1;
		update_player(game);
	}
	if (keycode == ESC)
	{
	}
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

void	check_exit_path(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == EXIT)
		*count -= 1;
	map[y][x] = WALL;
	if (map[y][x - 1] != WALL)
		check_exit_path(map, x - 1, y, count);
	if (map[y + 1][x] != WALL)
		check_exit_path(map, x, y + 1, count);
	if (map[y][x + 1] != WALL)
		check_exit_path(map, x + 1, y, count);
	if (map[y - 1][x] != WALL)
		check_exit_path(map, x, y - 1, count);
}

void	check_collectible_path(char **map, int x, int y, int *count)
{
	if (*count <= 0)
		return ;
	if (map[y][x] == COLLECT)
		*count -= 1;
	map[y][x] = WALL;
	if (map[y][x - 1] != WALL && map[y][x - 1] != EXIT)
		check_collectible_path(map, x - 1, y, count);
	if (map[y + 1][x] != WALL && map[y + 1][x] != EXIT)
		check_collectible_path(map, x, y + 1, count);
	if (map[y][x + 1] != WALL && map[y][x + 1] != EXIT)
		check_collectible_path(map, x + 1, y, count);
	if (map[y - 1][x] != WALL && map[y - 1][x] != EXIT)
		check_collectible_path(map, x, y - 1, count);
}

void	print_error(t_game *game, const char *err_msg)
{
	ft_putendl_fd((char*)err_msg, STDERR);
	free_game(game);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	t_game *game = game_init();
	get_map(game, argv[1]);
	print_map(game->map);
	return 0;
}

int	main2(int argc, char **argv)
{
	atexit(find_leaks);
	t_game	*game;
	char	*file_path;
	char	**map;
	int		count;

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
	if (check_c_e_p(game))
	{
		print_error(game, "Error: The map has wrong character");
	}


	map = map_dup(game->map, game->col_len);
	
	if (map == NULL)
	{
		free_game(game);
		perror("");
		return (1);
	}

	get_pos(game);
	print_map(game->map);

	// check if player can access to exit.
	count = 1;
	check_exit_path(map,
			game->player.position.x,
			game->player.position.y,
			&count);
	ft_free(map);
	if (count > 0)
	{
		printf("from exit\n");
		free_game(game);
		ft_putendl_fd("Error: The player could not access to exit or collectible", STDERR);
		return (1);
	}
	// check if player can access to collectible.
	count = game->count[2];
	map = map_dup(game->map, game->col_len);

	check_collectible_path(map,
			game->player.position.x,
			game->player.position.y,
			&count);

	ft_free(map);
	if (count > 0)
	{
		printf("from collectible\n");
		free_game(game);
		ft_putendl_fd("Error: The player could not access to exit or collectible", STDERR);
		return (1);
	}
	// TODO: check if mlx function failed
	game->mlx = mlx_init();
	get_images(game);
	game->screen_width = game->row_len * game->img_width;
	game->screen_height = game->col_len * game->img_height;

	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "so_long");

	mlx_key_hook(game->win, key_hook, game);
	mlx_mouse_hook(game->win, mouse_hook, game);

	render_game(game);
	
	mlx_loop(game->mlx);

	return (0);
}

