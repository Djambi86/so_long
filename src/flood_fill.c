/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:49:02 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/23 18:28:09 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_and_exit(char *a, char *b)
{
	if (a)
		free(a);
	if (b)
		free(b);
	exit(0);
}

void	flood_fill_init(t_map *map)
{
	char	*str_copy;
	int		i;

	i = 0;
	str_copy = ft_calloc((map->full_size + 1), sizeof(char));
	if (!str_copy)
		return ;
	ft_memcpy(str_copy, map->string, map->full_size);
	while (str_copy[i] != 'P')
		i++;
	flood_fill(i, str_copy, map);
	check_leftover(str_copy, map->string);
	free(str_copy);
}

void	flood_fill(int i, char *str_copy, t_map *map)
{
	if (str_copy[i] == '1')
		return ;
	str_copy[i] = '1';
	flood_fill(i + 1, str_copy, map);
	flood_fill(i + map->edges, str_copy, map);
	flood_fill(i - 1, str_copy, map);
	flood_fill(i - map->edges, str_copy, map);
	return ;
}

void	check_leftover(char *str_copy, char *str)
{
	int	i;

	i = 0;
	while (str_copy[i])
	{
		if (str_copy[i] == 'E')
		{
			ft_printf("You little trickster, the E is closed off :(!\n");
			free_and_exit(str_copy, str);
		}
		else if (str_copy[i] == 'P')
		{
			ft_printf("You little trickster, the P is closed off :(!\n");
			free_and_exit(str_copy, str);
		}
		else if (str_copy[i] == 'C')
		{
			ft_printf("You little trickster, the C is closed off :(!\n");
			free_and_exit(str_copy, str);
		}
		i++;
	}
	return ;
}
