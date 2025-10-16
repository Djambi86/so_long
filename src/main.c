/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:53:14 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/16 20:30:30 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_ber(char *str)
{
	int			res;
	const char	*ber;

	ber = str;
	ber = ft_strchr(ber, '.');
	res = ft_strncmp(ber, ".ber", 4);
	if (res > 0 || res < 0)
	{
		ft_printf("This ain't a .ber file handsome person!");
		exit (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("please put in a map, and only a map");
		return (0);
	}
	is_ber(argv[1]);
	map.fd = open(argv[1], O_RDONLY);
	map_read(&map);
	close(map.fd);
	map.fd = open(argv[1], O_RDONLY);
	rect_map(&map);
	close(map.fd);
	free(map.string);
}
