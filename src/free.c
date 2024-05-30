/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:18:09 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/30 18:48:03 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game_info *game)
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

void	free_img(t_game_info *game)
{
	mlx_destroy_image(game->mlx, game->textures.background);
	mlx_destroy_image(game->mlx, game->textures.collectible);
	mlx_destroy_image(game->mlx, game->textures.exit);
	mlx_destroy_image(game->mlx, game->textures.player);
	mlx_destroy_image(game->mlx, game->textures.wall);
}

int	close_game(t_game_info *game) // need to be int cus mlx_hook and nlx_key_hook require int
{
	free_map(game); 
	free_img(game); // here???
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx); //do i need ???
	exit(0);
	return(0);
}