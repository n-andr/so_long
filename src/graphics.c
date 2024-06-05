/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:57:07 by nandreev          #+#    #+#             */
/*   Updated: 2024/06/06 00:21:01 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_img(t_game_info *game)
{
	game->img_height = IMG_HEIGHT;
	game->img_width = IMG_WIDTH;
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
	"assets/goose_idle_on_green.xpm", &game->img_width, &game->img_height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx, \
	"assets/potion_pink_on_green.xpm", &game->img_width, &game->img_height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
	"assets/couldron_on-green.xpm", &game->img_width, &game->img_height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/wall_bush.xpm", &game->img_width, &game->img_height);
	game->textures.stone = mlx_xpm_file_to_image(game->mlx, \
	"assets/lonly_bush.xpm", &game->img_width, &game->img_height);
	game->textures.background = mlx_xpm_file_to_image(game->mlx, \
	"assets/grass_textured.xpm", &game->img_width, &game->img_height);
	if (game->textures.player == NULL || game->textures.background == NULL
		|| game->textures.collectible == NULL || game->textures.exit == NULL
		|| game->textures.wall == NULL || game->textures.stone == NULL)
	{
		write(1, "Error\nfail to open images\n", 26);
		close_game(game);
	}
}

void	load_borders(t_game_info *game, int i, int k)
{
	if (i == 0 || i == game->rows - 1 || k == 0 || k == game->columns - 1)
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.wall, k * 32, i * 32);
	else
		mlx_put_image_to_window(game->mlx, game->window, \
		game->textures.stone, k * 32, i * 32);
}

void	load_row(t_game_info *game, int i)
{
	int	k;

	k = 0;
	while (game->map[i][k])
	{
		if (game->map[i][k] == '1')
			load_borders(game, i, k);
		else if (game->map[i][k] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.background, k * 32, i * 32);
		else if (game->map[i][k] == 'C')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.collectible, k * 32, i * 32);
		else if (game->map[i][k] == 'P')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.player, k * 32, i * 32);
		else if (game->map[i][k] == 'E')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.exit, k * 32, i * 32);
		k++;
	}
}

void	load_map_graphics(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		load_row(game, i);
		i++;
	}
}
