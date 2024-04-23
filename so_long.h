/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:21:53 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/23 23:09:06 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct s_game_info
{
	char	**map;
	int		rows;
}	t_game_info;

int read_map(char *map, t_game_info *game);


//free
void	free_game(t_game_info *game);

//libft
int	ft_strlen(char *str);