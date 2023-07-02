#include "../include/so_long.h"

int	animate_fire(t_game *game)
{
	if (game->enemy.count == 2500)
	{
		if (game->enemy.flag == 4)
			game->enemy.flag = 0;
		mlx_put_image_to_window(game->mlx, game->win, game->space,
			2 * game->img_width, 2 * game->img_height);
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.imgs[game->enemy.flag],
				2 * game->img_width, 2 * game->img_height);
		game->enemy.flag += 1;
		game->enemy.count = 0;
	}
	game->enemy.count += 1;
	return 0;
}
