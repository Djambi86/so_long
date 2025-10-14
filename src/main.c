/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:53:14 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/14 20:51:04 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
	{
		ft_printf("please put in a map, and only a map");
		return (0);
	}
	map.fd = open(argv[1], O_RDONLY);
	map_read(&map);
	close(map.fd);
	map.fd = open(argv[1], O_RDONLY);
	rect_map(&map);
	close(map.fd);
	free(map.string);
}
