/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:03:37 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/04 13:57:05 by aabourri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	*get_image(t_game *game, const char *path_name)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, (char *)path_name,
			&game->img_width, &game->img_height);
	if (img == NULL)
	{
		print_error(game, "Error: Load img failed");
	}
	return (img);
}

static void	get_enemy_images(t_game *game)
{
	t_enemy	*enemy;

	enemy = &game->enemy;
	enemy->imgs[0] = get_image(game, "./textures/fire_1.xpm");
	enemy->imgs[1] = get_image(game, "./textures/fire_2.xpm");
	enemy->imgs[2] = get_image(game, "./textures/fire_3.xpm");
	enemy->imgs[3] = get_image(game, "./textures/fire_4.xpm");
}

static void	get_player_images(t_game *game)
{
	t_player	*player;

	player = &game->player;
	player->img_left[0] = get_image(game, "./textures/left.xpm");
	player->img_left[1] = get_image(game, "./textures/left2.xpm");
	player->img_left[2] = get_image(game, "./textures/left3.xpm");
	player->img_down[0] = get_image(game, "./textures/down.xpm");
	player->img_down[1] = get_image(game, "./textures/down2.xpm");
	player->img_down[2] = get_image(game, "./textures/down3.xpm");
	player->img_up[0] = get_image(game, "./textures/up.xpm");
	player->img_up[1] = get_image(game, "./textures/up2.xpm");
	player->img_up[2] = get_image(game, "./textures/up3.xpm");
	player->img_right[0] = get_image(game, "./textures/right.xpm");
	player->img_right[1] = get_image(game, "./textures/right2.xpm");
	player->img_right[2] = get_image(game, "./textures/right3.xpm");
}

void	get_images(t_game *game)
{
	get_player_images(game);
	get_enemy_images(game);
	game->space = get_image(game, "./textures/space.xpm");
	game->wall = get_image(game, "./textures/wall.xpm");
	game->collectible = get_image(game, "./textures/Cherry.xpm");
	game->exit = get_image(game, "./textures/exit.xpm");
}
