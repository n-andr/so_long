/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:18:09 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/24 20:18:10 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_game(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map[i]) //need to free one more that is already null?
	{
		//printf("line %d : %s", i, game->map[i]);
		free (game->map[i]);
		i ++;
	}
	free (game->map);
}

void	free_check_map(char **map)
{
	int	i;

	i = 0;
	while (map[i]) //need to free one more that is already null?
	{
		//printf("line %d : %s", i, game->map[i]);
		free (map[i]);
		i ++;
	}
	free (map);
}