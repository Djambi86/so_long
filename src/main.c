/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:53:14 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/10 17:50:35 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("please put in a map, and only a map");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	map_read(fd);
}
