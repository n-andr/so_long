/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:21:53 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/05 22:54:38 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
typedef struct s_game_info
{
	char	**map;
	int	rows;
	int	columns;
	int	collectibles;
	int	c_check;
	int	exit_check;
	void *mlx;
	void *window;
}	t_game_info;

int read_map(char *map, t_game_info *game);
int has_valid_path(t_game_info *game, char *map_adress);

//free
void	free_game(t_game_info *game);
void	free_check_map(char **map);
void	close_game(t_game_info *game);

//libft
//int	ft_strlen(char *str);
void	*ft_calloc(size_t n_items, size_t size);

#endif