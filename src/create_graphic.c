#include "../include/so_long.h"

void	create_graphic(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "So_long");
	mlx_loop(game->mlx);
}