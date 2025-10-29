/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabdulka <dabdulka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:44:19 by dabdulka          #+#    #+#             */
/*   Updated: 2025/10/29 18:26:28 by dabdulka         ###   ########.fr       */
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
# define TILE 32
# define WIDTH 1920
# define HEIGHT 1080
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct	s_map
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
	size_t		cols;
	size_t		rows;
	int			coins_left;
}	t_map;

typedef struct	s_img
{
	void	*ptr;
	int		w;
	int		h;
}	t_img;

typedef struct	s_textures
{
	t_img	wall;
	t_img	floor;
	t_img	coin;
	t_img	exit;
	t_img	player;
}	t_textures;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_map		*map;
	int			px;
	int			py;
	int			moves;
	t_textures	ex;
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
//void	create_graphic(t_game *game);
void	check_leftover(char *str_copy, char *str);
void	free_and_exit_string_map(char *a, char *b);
void	map_finalize_dims_and_player(t_map *m, int *px, int *py);
void	game_start(t_game *g, t_map *m);
int		on_destroy(t_game *g);
int		on_key(int key, t_game *g);
void	render_all(t_game *g);
char	map_at(t_map *m, int x, int y);
void	map_set(t_map *m, int x, int y, char c);
int		try_move(t_game *g, int dx, int dy);

#endif
