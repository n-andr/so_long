/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:12 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/25 13:53:08 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game_info game;
	printf("main\n"); // remove
	if (argc == 2) // need to check if map ends with .ber
	{
		printf("read map\n"); // remove
		read_map(argv[1], &game);
		
	}
	else
	{
		write(1, "Programm accepts only 1 argument\n", 33);
		exit(EXIT_FAILURE);
	}
	printf("map is ok\n");
	// game.mlx = mlx_init();
	// game.window = mlx_new_window(game.mlx, game.columns, game.rows, "so long");
	return (0);
}
