/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:47:44 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/29 20:49:29 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	i_hate_25lines_may_it_vanish(t_game *g, int nx, int ny, char t);

int	try_move(t_game *g, int dx, int dy)
{
	int		nx;
	int		ny;
	char	t;

	nx = g->px + dx;
	ny = g->py + dy;
	t = map_at(g->map, nx, ny);
	if (t == '1')
		return (0);
	if (t == 'E' && g->map->coins_left == 0)
	{
		g->moves++;
		g->px = nx;
		g->py = ny;
		render_all(g);
		ft_printf("\nYou win in %d moves!\n", g->moves);
		on_destroy(g);
	}
	return (i_hate_25lines_may_it_vanish(g, nx, ny, t));
}

static int	i_hate_25lines_may_it_vanish(t_game *g, int nx, int ny, char t)
{
	if (t == 'C')
	{
		g->map->coins_left--;
		map_set(g->map, nx, ny, '0');
	}
	g->px = nx;
	g->py = ny;
	g->moves++;
	return (1);
}

int	on_key(int key, t_game *g)
{
	int	moved;

	if (key == KEY_ESC)
		on_destroy(g);
	moved = 0;
	if (key == KEY_A)
		moved = try_move(g, -1, 0);
	if (key == KEY_D)
		moved = try_move(g, 1, 0);
	if (key == KEY_W)
		moved = try_move(g, 0, -1);
	if (key == KEY_S)
		moved = try_move(g, 0, 1);
	if (moved)
		render_all(g);
	return (0);
}
