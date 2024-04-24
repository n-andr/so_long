/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:21:53 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/24 19:29:31 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>

typedef struct s_game_info
{
	char	**map;
	int	rows;
	int	columns;
	void *mlx;
	void *window;
}	t_game_info;

int read_map(char *map, t_game_info *game);


//free
void	free_game(t_game_info *game);

//libft
int	ft_strlen(char *str);

#endif