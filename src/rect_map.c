/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:11:08 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/16 21:30:33 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_last(t_map *map)
{
	while (map->string[map->last_row] == '\n')
		map->last_row--;
	map->temp = map->last_row;
	while (map->string[map->last_row] != '\n')
	{
		if (map->string[map->last_row] != '1')
		{
			ft_printf("Last row is not all Ones!\n");
			free(map->string);
			exit(0);
		}
		map->last_row--;
	}
	map->last_row++;
	while (map->first_row != map->temp)
	{
		if (map->string[map->first_row] != '1'
			|| map->string[map->last_row] != '1')
		{
			printf("The middle ground ain't safe!\n");
			exit (0);
		}
		map->first_row += (map->edges);
		map->last_row -= (map->edges);
	}
}

void	check_first(t_map *map)
{
	int	i;

	i = 0;
	map->first_row = 0;
	map->last_row = 0;
	while (map->string[i] != '\n')
	{
		if (map->string[i] != '1')
		{
			ft_printf("First row is not all Ones!\n");
			free (map->string);
			exit(0);
		}
		map->first_row++;
		i++;
	}
	map->first_row--;
	map->last_row = map->full_size - 1;
	map->edges = map->first_row + 2;
	check_last(map);
}

void	map_dup(t_map *map, ssize_t bytes)
{
	int	i;
	int	j;

	j = 0;
	while (bytes > 0)
	{
		map->buf[bytes] = '\0';
		i = 0;
		while (map->buf[i])
		{
			map->string[j] = map->buf[i];
			i++;
			j++;
		}
		bytes = read(map->fd, map->buf, BUF_SIZE);
	}
	if (bytes < 0)
	{
		free(map->string);
		perror("Error while reading map: ");
		return ;
	}
}

void	rect_map(t_map *map)
{
	ssize_t	bytes;

	map->string = ft_calloc((map->full_size + 1), sizeof(char));
	if (!map->string)
		return ;
	bytes = read(map->fd, map->buf, BUF_SIZE);
	map_dup(map, bytes);
	check_first(map);
	ft_printf("Result meines string: \n%s", map->string);
}
