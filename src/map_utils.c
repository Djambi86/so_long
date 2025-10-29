/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:20:01 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/29 18:27:29 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	locate_p_and_coins(t_map *m, int *px, int *py)
{
	size_t	i;

	i = 0;
	m->coins_left = 0;
	while (m->string[i])
	{
		if (m->string[i] == 'P')
		{
			*px = (int)(i % m->edges);
			*py = (int)(i / m->edges);
		}
		else if (m->string[i] == 'C')
			m->coins_left++;
		i++;
	}
}

void	map_finalize_dims_and_player(t_map *m, int *px, int *py)
{
	m->cols = m->edges - 1;
	m->rows = (size_t)(m->full_size / m->edges);
	locate_p_and_coins(m, px, py);
}
