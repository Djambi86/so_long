/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 19:11:08 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/14 22:08:47 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_row(t_map *map)
{
	if (map->string[map->last_row] == '\n')
	{	
		map->last_row--;
		while (map->string[map->last_row] != '\n')
		{
			if (map->string[map->last_row] != '1')
			{
				ft_printf("Last row is not all Ones!\n");
				free (map->string);
				exit (0);
			}
			map->last_row--;
		}
	}
	else
	{
		while (map->string[map->last_row] != '\n')
		{
			if (map->string[map->last_row] != '1')
			{
				ft_printf("Last row is not all Ones!\n");
				free (map->string);
				exit (0);
			}
			map->last_row--;
		}
	}
}

void	check_map(t_map *map)
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
	check_row(map);	
}

void rect_map(t_map *map)
{
	int i;
	int j;
	ssize_t bytes;

	map->string = (char *)malloc(sizeof(char) * (map->full_size + 1));
	if (!map->string)
		return;
	j = 0;
	bytes = read(map->fd, map->buf, BUF_SIZE);
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
		return;
	}
	map->string[map->full_size] = '\0';
	check_map(map);
	ft_printf("Result meines string: \n%s", map->string);
}
