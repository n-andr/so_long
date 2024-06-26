/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:12 by nandreev          #+#    #+#             */
/*   Updated: 2024/06/06 00:28:59 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_moves(t_game_info *game)
{
	char	*moves;

	game->moves_count ++;
	moves = ft_itoa(game->moves_count);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	free(moves);
}

// need to be int cus mlx_hook and nlx_key_hook require int
// more like key unpressed
int	key_pressed(int key, t_game_info *game)
{
	if (key == 119 || key == 115 \
	|| key == 100 || key == 97)
	{
		move_p(game, key);
	}
	else if (key == 65307)
	{
		close_game(game);
	}
	return (0);
}

void	is_ber(char *map_adress)
{
	if (map_adress[ft_strlen(map_adress) - 1] == 'r'
		&& map_adress[ft_strlen(map_adress) - 2] == 'e'
		&& map_adress[ft_strlen(map_adress) - 3] == 'b'
		&& map_adress[ft_strlen(map_adress) - 4] == '.')
		return ;
	else
	{
		write(1, "Error\nProgramm accepts only .ber files\n", 39);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_game_info	game;

	if (argc == 2)
	{
		is_ber(argv[1]);
		read_map(argv[1], &game);
	}
	else
	{
		write(1, "Error\nProgramm accepts only 1 argument\n", 39);
		exit(EXIT_FAILURE);
	}
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.columns * 32, \
	game.rows * 32, "so long");
	open_img(&game);
	load_map_graphics(&game);
	mlx_hook((game.window), 17, 0, close_game, &game);
	mlx_key_hook(game.window, key_pressed, &game);
	mlx_loop(game.mlx);
	return (0);
}

// mlx_hook - for different events (mouse movements, close the window etc)
// mlx_key_hook - only for keyboard events
//need to handle cntr c to have no leaks???
