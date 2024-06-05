/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:18:09 by nandreev          #+#    #+#             */
/*   Updated: 2024/06/05 16:18:19 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_error(t_game_info *game, int file, char *message)
{
	write(1, message, ft_strlen(message));
	if (file != -1)
	{
		close(file);
	}
	free_map(game);
	exit(EXIT_FAILURE);
}

void	free_map(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free (game->map[i]);
		i ++;
	}
	free (game->map);
}

void	free_check_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
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

int	close_game(t_game_info *game)
{
	free_map(game);
	free_img(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
