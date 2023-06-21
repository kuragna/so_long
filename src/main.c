/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/21 19:22:49 by aabourri         ###   ########.fr       */
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

typedef struct s_vector
{
	int	x;
	int	y;
} t_vector;

typedef struct s_player
{
	int	img_width;
	int	img_height;
	void	*img;
	t_vector position;
} t_player;

typedef struct s_game
{
	size_t	count_move;
	int	count_collectible;
	int	img_width;
	int	img_height;
	int	screen_width;
	int	screen_height;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*collectible;
	void	*space;
	void	*exit;
	void	*enemy;
	char	**map;
	t_player player;
	t_vector exit_pos;
} t_game;


enum e_keys
{
	A 	= 0X0,		// 0
	S 	= 0X1,		// 1
	D 	= 0X2,		// 2
	W 	= 0Xd,		// 13
	ESC = 0X35,		// 53
};

enum e_colors
{
	RED		= 0XFF0000,
	GREEN	= 0X00FF00,
	BLUE 	= 0X0000FF,
	DARK 	= 0X181818,
	YELLOW	= 0XFFF26E,
	WHITE	= 0XFFFFFF,
};

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

void	get_pos(t_game *game, int size)
{
	int	y;
	int	len;

	y = 0;
	len = ft_strlen(game->map[0]) - 1;
	while (++y < size - 1)
	{
		int	x = 0;
		while (++x < len)
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
			if (game->map[y][x] == 'C')
			{
				game->count_collectible += 1;
				PUT_IMAGE(game->collectible);
			}
			if (game->map[y][x] == 'N')
				PUT_IMAGE(game->enemy);
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
		game->count_collectible -= 1;

	mlx_put_image_to_window(game->mlx, game->win, game->wall, 
			x * game->img_width, y * game->img_height);
	game->count_move += 1;
	count = ft_itoa(game->count_move);
// 	mlx_put_image_to_window(game->mlx, game->win, game->wall, (game->screen_width / 2) - 11.5, 0);
	mlx_string_put(game->mlx, game->win, (game->screen_width / 2), 1, WHITE, count);
	free(count);
	printf("number of movements : %ld\n", game->count_move);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	(void)param;
	(void)x;

	if (button == BTN_LEFT && y < 0)
	{
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
		if (game->map[y - 1][x] == 'E' && game->count_collectible > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.y -= 1;
		update_player(game);
	}
	if (keycode == S && game->map[y + 1][x] != '1') // DOWN
	{
		if (game->map[y + 1][x] == 'E' && game->count_collectible > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.y += 1;
		update_player(game);
	}
	if (keycode == A && game->map[y][x - 1] != '1') // LEFT
	{
		if (game->map[y][x - 1] == 'E' && game->count_collectible > 0)
			return 1;
		mlx_put_image_to_window(game->mlx, game->win, game->space, 
				x * game->img_width, y * game->img_height);
		game->player.position.x -= 1;
		update_player(game);
	}
	if (keycode == D && game->map[y][x + 1] != '1') // RIGHT
	{
		if (game->map[y][x + 1] == 'E' && game->count_collectible > 0)
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

int	main(int argc, char **argv)
{
// 	atexit(find_leaks);
	char	*file_path;
	int	size;
	t_game	*game;

	file_path = argv[1];
	if (argc != 2 || check_file_path(file_path))
	{
		printf("usage: so_long maps/file_name.ber\n");
		return 1;
	}

	game = game_init();
	game->mlx = mlx_init();
	game->map = get_map(file_path, &size);
	if (game->map == NULL)
	{
		printf("Error: could not read a file\n");
		return 1;
	}


	print_map(game->map);

	get_pos(game, size);
	

// 	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
// 			&game->img_width, &game->img_height);
// 	game->space = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm", &game->img_width, &game->img_height);

	get_images(game);

	game->screen_width = (ft_strlen(game->map[0]) - 1) * game->img_width;
	game->screen_height = size * game->img_height;
	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "so_long");


	mlx_key_hook(game->win, key_hook, game);

	mlx_mouse_hook(game->win, mouse_hook, game);

	print_map(game->map);
	render_game(game);
	
	get_pos(game, size);

	mlx_put_image_to_window(game->mlx, game->win, game->wall,
			game->player.position.x * game->img_width, game->player.position.y * game->img_height);


	mlx_loop(game->mlx);
	return 0;

	if (game->map[0] == NULL || check_walls(game->map, size))
	{
		printf("Error: invalid walls\n");
		return 1;
	}

	if (check_c_e_p(game->map, size))
	{
		printf("Error: invalid player, exit or collectible\n");
		return 1;
	}

	print_map(game->map);

	return 0;
}
