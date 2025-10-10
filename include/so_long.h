/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:19 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/10 17:57:28 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <unistd.h>
# include "../include/ft_printf/ft_printf.h"

# define BUF_SIZE 1024

typedef struct s_map
{
	ssize_t	r;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
	char	buf[BUF_SIZE];
}	t_map;

int	map_read(int fd);
int	validate_counts(t_map *map);

#endif
