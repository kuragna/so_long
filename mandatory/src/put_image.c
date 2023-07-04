#include "../../include/so_long.h"

void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
			x * game->img_width, y * game->img_height);	
}
