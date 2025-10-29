/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:56:11 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/29 18:31:55 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	destroy_textures(t_game *g)
{
	if (g->ex.wall.ptr)
		mlx_destroy_image(g->mlx, g->ex.wall.ptr);
	if (g->ex.floor.ptr)
		mlx_destroy_image(g->mlx, g->ex.floor.ptr);
	if (g->ex.coin.ptr)
		mlx_destroy_image(g->mlx, g->ex.coin.ptr);
	if (g->ex.exit.ptr)
		mlx_destroy_image(g->mlx, g->ex.exit.ptr);
	if (g->ex.player.ptr)
		mlx_destroy_image(g->mlx, g->ex.player.ptr);
}

int	on_destroy(t_game *g)
{
	destroy_textures(g);
	if (g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	if (g->map && g->map->string)
		free(g->map->string);
	exit(0);
	return (0);
}
