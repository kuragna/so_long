/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:10:46 by aabourri          #+#    #+#             */
/*   Updated: 2023/06/16 18:01:30 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

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

#define EXTENSION ".ber"

typedef struct s_vector
{
	int	x;
	int	y;
} t_vector;

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




void	get_pos(char **lines, int size, char c, t_vector *ptr)
{
	char	*line;
	int	i;

	i = 1;
	while (i < size - 1)
	{
		line = ft_strchr(lines[i], c);
		if (line != NULL)
			break ;
		i++;
	}
	ptr->y = i;
	ptr->x = (int)(line - lines[i]);
}


#define WIDTH 800
#define HEIGHT 800
#define STR(s) #s
#define BTN_LEFT 1


enum e_keys
{
	A = 0,
	S = 1,
	D = 2,
	W = 13,
	EXIT = 53,
};

/*
 *	W:	13
 *	A:	0
 *	S:	1
 *	D:	2
 *	ESC: 53
 * */


int	key_hook(int keycode)
{
	if (keycode == A)
		printf("A\n");
	if (keycode == S)
		printf("S\n");
	if (keycode == D)
		printf("D\n");
	if (keycode == W)
		printf("W\n");
	if (keycode == EXIT)
		exit(0);
	return 0;
}

/**/

int	mouse_hook(int button, int x, int y)
{
	(void)button;
	(void)x;
	(void)y;

	printf("not impelemted yet!\n");
	return (0);
}

int	gcd(int a, int b)
{
	if (b != 0)
		return (gcd(b, a % b));
	return (a);
}

// 1111111
// 1000001
// 1111111
// 1000001
// 1000001

int	main2(void)
{
	int	width = 32;
	int	height = 32;

	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, WIDTH, HEIGHT, "so_long");


// 	void	*img = mlx_new_image(mlx, width, height);

	mlx_xpm_file_to_image(mlx, "./wall.xpm", &width, &height);

// 	for (int y = 0; y < HEIGHT; y++)
// 	{
// 		for (int x = 0; x < WIDTH; x++)
// 		{
// 			mlx_put_image_to_window(mlx, win, xpm, x, y);
// 		}
// 	}



// 	for (int i = 0; i < 32; i++)
// 	{
// 		mlx_put_image_to_window(mlx, win, xpm, width * i, 0);
// 		mlx_put_image_to_window(mlx, win, xpm, 0, height * i);
// 		mlx_put_image_to_window(mlx, win, xpm, width * 32, height * i);
// 		mlx_put_image_to_window(mlx, win, xpm, width * i, height * 32);
// 	}
	mlx_key_hook(win, key_hook, NULL);
	mlx_loop(mlx);
	return 0;
}

typedef struct s_game
{
	int	img_width;
	int	img_height;
	int	screen_width;
	int	screen_height;
	void	*mlx;
	void	*win;
	void	*img;
	t_vector player;
	t_vector exit;
} t_game;

t_game *game_init()
{
	t_game *game;
	size_t	size;

	size = sizeof(*game);
	game = malloc(size);
	ft_memset(game, 0, size);
	return (game);
}

void	render_walls(t_game *game, char **lines)
{
	size_t	width = (game->screen_width / game->img_width);
	size_t	height = (game->screen_height / game->img_height);

	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			if (lines[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img,
						game->img_width * x, game->img_height * y);
		}
	}
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

	char	*lines[256];
	int	size = 0;

	while ((lines[size] = get_next_line(fd)))
		size++;
	lines[size] = NULL;


	game->mlx = mlx_init();
	game->img = mlx_xpm_file_to_image(game->mlx, "./wall.xpm", &game->img_width, &game->img_height);

	game->screen_width = (ft_strlen(lines[0]) - 1) * game->img_width;
	game->screen_height = size * game->img_height;
	game->win = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "so_long");

	render_walls(game, lines);

	print_map(lines);

	get_pos(lines, size, 'P', &game->player);
	printf("player(%d, %d)\n", game->player.x, game->player.y);

// 	mlx_pixel_put(game->mlx, game->win, game->player.x, game->player.y, RED);

	mlx_loop(game->mlx);

	return 0;

	if (lines[0] == NULL || check_walls(lines, size))
	{
		printf("Error: invalid walls\n");
		return 1;
	}

	if (check_c_e_p(lines, size))
	{
		printf("Error: invalid player, exit or collectible\n");
		return 1;
	}

	print_map(lines);


	return 0;
}

