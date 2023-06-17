/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/17 19:28:47 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

int	key_hook(int keycode, void *param);

/*
 *	TODO: File name with .ber extension.- DONE
 *	TODO: Valid file path. - DONE
 *	TODO: The map has 1 exit, 1 player and at least 1 collectible. - DONE
 *	TODO: The map must be rectangular. - DONE
 *	TODO: The map must be closed/surrounded by walls. - DONE
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

typedef struct s_game
{
	// player move count
	size_t	move_count;
	int	img_width;
	int	img_height;
	int	screen_width;
	int	screen_height;
	void	*mlx;
	void	*win;
	void	*img;
	void	*p_img;
	char	*map[256];
	t_vector player;
	t_vector exit;
} t_game;

enum e_keys
{
	A = 0X0,		// 0
	S = 0X1,		// 1
	D = 0X2,		// 2
	W = 0Xd,		// 13
	EXIT = 0X35,	// 53
};

enum e_colors
{
	RED = 0XFF0000,
	BLUE = 0X0000FF,
	DARK = 0X181818,
	WHITE = 0XFFFFFF,
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
				game->player.x = x;
				game->player.y = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
			}
		}
	}
}



int	mouse_hook(int button, int x, int y)
{
	(void)button;
	(void)x;
	(void)y;

	printf("not impelemted yet!\n");
	return (0);
}

void	fill_screen(t_game *game)
{
	for (int y = 0; y < game->screen_height; y++)
	{
		for (int x = 0; x < game->screen_width; x++)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0X0);
		}
	}
}

// void	put_square(t_game *game)
// {
// 	int	height = (game->screen_height / game->)
// 	for (int y = 0; y < game->screen_height; y++)
// 	{
// 		for (int x = 0; x < game->screen_width; x++)
// 		{
// 			if ()
// 		}
// 	}
// }

void	render_walls(t_game *game)
{
	size_t	width = (game->screen_width / game->img_width);
	size_t	height = (game->screen_height / game->img_height);

	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img,
						game->img_width * x, game->img_height * y);
		}
	}
}


int	main2()
{
	t_game	*game = game_init();

	game->screen_width = 800;
	game->screen_height = 800;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "so_long");


	mlx_key_hook(game->win, key_hook, game);



	mlx_loop(game->mlx);

	return 0;
}

void	update_player(t_game *game)
{
	fill_screen(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img,
		game->player.x * game->img_width, game->player.y * game->img_height);
	game->move_count += 1;
	mlx_string_put(game->mlx, game->win, game->screen_width / 2, 0, WHITE, ft_itoa(game->move_count));
	printf("Total of move: %ld\n", game->move_count);
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
	int	y = game->player.y;
	int	x = game->player.x;

	if (keycode == W && game->map[y - 1][x] != '1')
	{
		printf("UP\n");
		game->player.y -= 1;
		update_player(game);
	}
	if (keycode == S && game->map[y + 1][x] != '1')
	{
		printf("DOWN\n");
		game->player.y += 1;
		update_player(game);
	}
	if (keycode == A && game->map[y][x - 1] != '1')
	{
		printf("LEFT\n");
		game->player.x -= 1;
		update_player(game);
	}
	if (keycode == D && game->map[y][x + 1] != '1')
	{
		printf("RIGHT\n");
		game->player.x += 1;
		update_player(game);
	}
	if (keycode == EXIT)
		exit(0);
	return 0;
}



int	main(int argc, char **argv)
{
	char	*file_path;
	t_game	*game = game_init();

	file_path = argv[1];
	if (argc != 2 || check_file_path(file_path))
	{
		printf("usage: so_long maps/file_name.ber\n");
		return 1;
	}

	int	fd = open(file_path, O_RDONLY);

	if (fd == -1)
	{
		printf("Error: %s\n", strerror(errno));
		return 1;
	}
// 	char	*map[256];
	int	size = 0;

	while ((game->map[size] = get_next_line(fd)))
		size++;
	game->map[size] = NULL;

	print_map(game->map);

	get_pos(game, size);


	game->mlx = mlx_init();
	game->img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm", &game->img_width, &game->img_height);


	game->screen_width = (ft_strlen(game->map[0]) - 1) * game->img_width;
	game->screen_height = size * game->img_height;
	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "so_long");

	mlx_key_hook(game->win, key_hook, game);

	print_map(game->map);
	
	get_pos(game, size);

	mlx_put_image_to_window(game->mlx, game->win, game->img,
			game->player.x * game->img_width, game->player.y * game->img_height);
	

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
