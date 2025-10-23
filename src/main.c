/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:53:14 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/23 19:09:12 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_ber(char *str)
{
	int			res;

	str = ft_strchr(str, '/');
	if (!str)
		exit (0);
	if (str[1] == '.')
	{
		ft_printf("NUH HU, I don't want a hidden file!\n");
		exit(0);
	}
	str = ft_strchr(str, '.');
	res = ft_strncmp(str, ".ber", 4);
	if (res > 0 || res < 0)
	{
		ft_printf("This ain't a .ber file handsome person!\n");
		exit (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf("please put in a map, and only a map\n");
		return (0);
	}
	is_ber(argv[1]);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd == -1)
		return (0);
	map_read(&map);
	close(map.fd);
	map.fd = open(argv[1], O_RDONLY);
	if (map.fd == -1)
		return (0);
	rect_map(&map);
	close(map.fd);
	free(map.string);
}
