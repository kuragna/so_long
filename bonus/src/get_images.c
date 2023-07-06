/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabourri <aabourri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:03:37 by aabourri          #+#    #+#             */
/*   Updated: 2023/07/06 15:39:07 by aabourri         ###   ########.fr       */
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
	player->imgs_left[0] = get_image(game, "./textures/left.xpm");
	player->imgs_left[1] = get_image(game, "./textures/left2.xpm");
	player->imgs_left[2] = get_image(game, "./textures/left3.xpm");
	player->imgs_down[0] = get_image(game, "./textures/down.xpm");
	player->imgs_down[1] = get_image(game, "./textures/down2.xpm");
	player->imgs_down[2] = get_image(game, "./textures/down3.xpm");
	player->imgs_up[0] = get_image(game, "./textures/up.xpm");
	player->imgs_up[1] = get_image(game, "./textures/up2.xpm");
	player->imgs_up[2] = get_image(game, "./textures/up3.xpm");
	player->imgs_right[0] = get_image(game, "./textures/right.xpm");
	player->imgs_right[1] = get_image(game, "./textures/right2.xpm");
	player->imgs_right[2] = get_image(game, "./textures/right3.xpm");
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
