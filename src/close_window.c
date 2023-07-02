#include "../include/so_long.h"

int	close_win(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}
