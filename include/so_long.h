/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:19 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/23 19:31:35 by dabdulka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
//# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include "../include/ft_printf/ft_printf.h"
# include "../include/libft/libft.h"

# define BUF_SIZE 4000

typedef struct s_map
{
	ssize_t		r;
	int			c_cnt;
	int			e_cnt;
	int			p_cnt;
	char		buf[BUF_SIZE];
	char		*string;
	int			fd;
	size_t		full_size;
	size_t		first_row;
	size_t		other_row;
	size_t		last_row;
	size_t		temp;
	size_t		edges;
}	t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
}	t_game;

int		map_read(t_map *map);
void	validate_counts(t_map *map);
void	rect_map(t_map *map);
void	check_map(t_map *map);
void	check_row(t_map *map);
void	map_dup(t_map *map, ssize_t bytes);
int		is_ber(char *str);
void	check_middle(t_map *map);
void	flood_fill_init(t_map *map);
void	flood_fill(int i, char *str_copy, t_map *map);
void	check_leftover(char *str_copy, char *str);
void	create_graphic(t_game *game);

#endif
