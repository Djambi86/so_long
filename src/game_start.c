/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:23:57 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/29 20:46:16 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	load_one(void *mlx, t_img *dst, char *path, t_game *g)
{
	dst->ptr = mlx_xpm_file_to_image(mlx, path, &dst->w, &dst->h);
	if (!dst->ptr)
	{
		ft_printf("Failed to load: %s\n", path);
		on_destroy(g);
	}
}

static void	load_textures(t_game *g, t_textures *ex)
{
	ft_memset(ex, 0, sizeof(t_textures));
	load_one(g->mlx, &g->ex.wall, "./tiles/wall.xpm", g);
	load_one(g->mlx, &g->ex.floor, "./tiles/floor.xpm", g);
	load_one(g->mlx, &g->ex.coin, "./tiles/coin.xpm", g);
	load_one(g->mlx, &g->ex.exit, "./tiles/exit.xpm", g);
	load_one(g->mlx, &g->ex.player, "./tiles/player.xpm", g);
}

void	game_start(t_game *g, t_map *m)
{
	int	win_w;
	int	win_h;

	g->mlx = mlx_init();
	if (!g->mlx)
		exit(0);
	g->map = m;
	g->moves = 0;
	win_w = (int)(m->cols * TILE);
	win_h = (int)(m->rows * TILE);
	g->win = mlx_new_window(g->mlx, win_w, win_h, "so_long");
	if (!g->win)
	{
		mlx_destroy_display(g->mlx);
		free(g->map->string);
		free(g->mlx);
		exit(0);
	}
	load_textures(g, &g->ex);
	mlx_hook(g->win, 2, 1L << 0, (int (*)(void))on_key, g);
	mlx_hook(g->win, 17, 0, (int (*)(void))on_destroy, g);
	render_all(g);
	mlx_loop(g->mlx);
}
