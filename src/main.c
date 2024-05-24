/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:12 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/24 16:27:56 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// need to be int cus mlx_hook and nlx_key_hook require int
int	key_pressed(int key, t_game_info *game) // more like key unpressed???
{
	if (key == 119 || key == 115 \
	|| key == 100 || key == 97)
	{
		/* code */
	}
	else if (key == 65307)
	{
		close_game(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_info game;

	if (argc == 2) // need to check if map ends with .ber
	{
		read_map(argv[1], &game);	
	}
	else
	{
		write(1, "Programm accepts only 1 argument\n", 33);
		exit(EXIT_FAILURE);
	}
	// printf("map is ok\n"); // remove
	//need to handle cntr c to have no leaks???
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.columns * 32, \
	game.rows * 32, "so long");
	open_img(&game);
	load_graphics(&game);
	mlx_hook((game.window), 17, 0, close_game, &game);
	mlx_key_hook(game.window, key_pressed, &game);
	mlx_loop(game.mlx);
	return (0);
}

// mlx_hook - for different events (mouse movements, close the window etc)
// mlx_key_hook - only for keyboard events