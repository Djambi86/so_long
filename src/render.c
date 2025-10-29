/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:35:19 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/29 18:30:21 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static size_t	idx_of(t_map *m, int x, int y)
{
	return ((size_t)y * m->edges + (size_t)x);
}

char	map_at(t_map *m, int x, int y)
{
	if (x < 0 || y < 0)
		return ('1');
	if ((size_t)x >= m->cols || (size_t)y >= m->rows)
		return ('1');
	return (m->string[idx_of(m, x, y)]);
}

void	map_set(t_map *m, int x, int y, char c)
{
	m->string[idx_of(m, x, y)] = c;
}

static void	put(t_game *g, t_img img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img.ptr, x * TILE, y * TILE);
}

void	render_all(t_game *g)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < (int)g->map->rows)
	{
		x = 0;
		while (x < (int)g->map->cols)
		{
			c = map_at(g->map, x, y);
			put(g, g->ex.floor, x, y);
			if (c == '1')
				put(g, g->ex.wall, x, y);
			else if (c == 'C')
				put(g, g->ex.coin, x, y);
			else if (c == 'E')
				put(g, g->ex.exit, x, y);
			x++;
		}
		y++;
	}
	put(g, g->ex.player, g->px, g->py);
	ft_printf("\rMoves: %d | Coins left: %d\n", g->moves, g->map->coins_left);
}
