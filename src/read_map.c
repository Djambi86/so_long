/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:41:08 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/10 18:18:49 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	count_components(t_map *map)
{
	ssize_t	i;

	i = 0;
	while (i < map->r)
	{
		if (map->buf[i] == 'C')
			map->c_cnt++;
		else if (map->buf[i] == 'E')
			map->e_cnt++;
		else if (map->buf[i] == 'P')
			map->p_cnt++;
		else if (map->buf[i] != 'C' || map->buf[i] != 'E' || map->buf[i] != 'P'
			|| map->buf[i] != '1' || map->buf[i] != '0')
		{
			ft_printf("Invalid Character found!");
			exit(1);
		}
		i++;
	}
}

int	validate_counts(t_map *map)
{
	if (map->c_cnt < 1)
	{
		ft_printf("No collectibles in sight, give me collectibles!\n");
		return (0);
	}
	else if (map->e_cnt != 1)
	{
		ft_printf("No more or less than 1 Exit please!\n");
		return (0);
	}
	else if (map->p_cnt != 1)
	{
		ft_printf("No more or less than 1 Player please!\n");
		return (0);
	}
	ft_printf("The map looks good!");
	return (1);
}

int	map_read(int fd)
{
	t_map	map;

	map.c_cnt = 0;
	map.e_cnt = 0;
	map.p_cnt = 0;
	map.r = read(fd, map.buf, BUF_SIZE);
	while (map.r > 0)
	{
		count_components(&map);
		map.r = read(fd, map.buf, BUF_SIZE);
	}
	if (map.r < 0)
	{
		perror("Error while reading map:");
		return (0);
	}
	return (validate_counts(&map));
}

/* int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("please put in a map, and only a map");
		return (0);
	}
	int fd;
	fd = open(argv[1], O_RDONLY);
	map_read(fd);
} */