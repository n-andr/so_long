/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:21:53 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/28 14:26:05 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define IMG_WIDTH 32
# define IMG_HEIGHT 32

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include "src/get_next_line/get_next_line.h"
# include "mlx.h"
# include <stdio.h>

// if complains about include "mlx.h"
//sudo cp libmlx.a /usr/local/lib/
// sudo cp mlx.h /usr/local/include/

typedef struct s_textures
{
	void	*player;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*background;
}	t_textures;

typedef struct s_game_info
{
	char	**map;
	int	rows;
	int	columns;
	int	p_position_row;
	int p_position_col;
	int	img_width;
	int	img_height;
	int	collectibles;
	int moves_count;
	int	c_count;
	int	exit_check;
	void *mlx;
	void *window;
	t_textures	textures;
}	t_game_info;

int read_map(char *map, t_game_info *game);
int has_valid_path(t_game_info *game, char *map_adress);
void	find_p(t_game_info *game, char **map);
int	key_pressed(int key, t_game_info *game);

// graphics
void	open_img(t_game_info *game);
void	load_map_graphics(t_game_info *game);

//moves
void	move_p(t_game_info *game, int keycode);
void	count_moves(t_game_info *game);


//free
void	free_map(t_game_info *game);
void	free_check_map(char **map);
int		close_game(t_game_info *game);

//libft
//int	ft_strlen(char *str);
void	*ft_calloc(size_t n_items, size_t size);
char	*ft_itoa(int n);

#endif