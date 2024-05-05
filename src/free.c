/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:18:09 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/05 23:23:47 by Natalia          ###   ########.fr       */
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

int	close_game(t_game_info *game) // need to be int cus mlx_hook and nlx_key_hook require int
{
	mlx_destroy_window(game->window, game->window);
	mlx_destroy_display(game->mlx);
	free_game(game);
	exit(0);
	return(0);
}