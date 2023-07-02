#include "../include/so_long.h"

static void get_enemy_images(t_enemy *enemy, void *mlx)
{
	enemy->imgs[0] = mlx_xpm_file_to_image(mlx, "./textures/fire_1.xpm",
			&enemy->img_width, &enemy->img_height);	
	enemy->imgs[1] = mlx_xpm_file_to_image(mlx, "./textures/fire_2.xpm",
			&enemy->img_width, &enemy->img_height);	
	enemy->imgs[2] = mlx_xpm_file_to_image(mlx, "./textures/fire_3.xpm",
			&enemy->img_width, &enemy->img_height);	
	enemy->imgs[3] = mlx_xpm_file_to_image(mlx, "./textures/fire_4.xpm",
			&enemy->img_width, &enemy->img_height);	
}

static void	get_player_images(t_player *player, void *mlx)
{
	player->player_left[0] = mlx_xpm_file_to_image(mlx, "./textures/player_left.xpm",
		&player->img_width, &player->img_height);
	player->player_left[1] = mlx_xpm_file_to_image(mlx, "./textures/player_left2.xpm",
		&player->img_width, &player->img_height);
	player->player_left[2] = mlx_xpm_file_to_image(mlx, "./textures/player_left3.xpm",
		&player->img_width, &player->img_height);
	player->player_down[0] = mlx_xpm_file_to_image(mlx, "./textures/player_down.xpm",
		&player->img_width, &player->img_height);
	player->player_down[1] = mlx_xpm_file_to_image(mlx, "./textures/player_down2.xpm",
		&player->img_width, &player->img_height);
	player->player_down[2] = mlx_xpm_file_to_image(mlx, "./textures/player_down3.xpm",
		&player->img_width, &player->img_height);
	player->player_up[0] = mlx_xpm_file_to_image(mlx, "./textures/player_up.xpm",
		&player->img_width, &player->img_height);
	player->player_up[1] = mlx_xpm_file_to_image(mlx, "./textures/player_up2.xpm",
		&player->img_width, &player->img_height);
	player->player_up[2] = mlx_xpm_file_to_image(mlx, "./textures/player_up3.xpm",
		&player->img_width, &player->img_height);
	player->player_right[0] = mlx_xpm_file_to_image(mlx, "./textures/player_right.xpm",
		&player->img_width, &player->img_height);
	player->player_right[1] = mlx_xpm_file_to_image(mlx, "./textures/player_right2.xpm",
		&player->img_width, &player->img_height);
	player->player_right[1] = mlx_xpm_file_to_image(mlx, "./textures/player_right3.xpm",
		&player->img_width, &player->img_height);
}

void	get_images(t_game *game)
{
	get_player_images(&game->player, game->mlx);
	get_enemy_images(&game->enemy, game->mlx);
	game->space = mlx_xpm_file_to_image(game->mlx, "./textures/space.xpm",
			&game->img_width, &game->img_height);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&game->img_width, &game->img_height);
	game->collectible = mlx_xpm_file_to_image(game->mlx, "./textures/Cherry.xpm",
			&game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&game->img_width, &game->img_height);
}
