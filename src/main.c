/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:12 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/26 18:18:22 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	printf("map is ok\n");
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.columns * 32, \
	game.rows * 32, "so long");
	mlx_loop(game.mlx);
	return (0);
}
