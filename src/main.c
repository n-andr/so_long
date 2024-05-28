/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:12 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/28 17:26:15 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count_moves(t_game_info *game)
{
	char	*moves;

	game->moves_count ++;
	printf("count_moves : moves %i\n", game->moves_count); // remove
	moves = ft_itoa(game->moves_count);
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	printf("count_moves : moves %s\n", moves); // remove
	free(moves);
}
// need to be int cus mlx_hook and nlx_key_hook require int
int	key_pressed(int key, t_game_info *game) // more like key unpressed???
{
	if (key == 119 || key == 115 \
	|| key == 100 || key == 97)
	{
		printf("key_pressed : %i\n", key); // remove
		move_p(game, key);
	}
	else if (key == 65307)
	{
		printf("key_pressed : %i\n", key); // remove
		close_game(game);
	}
	printf("key_pressed : collectibles %i\n", game->collectibles); // remove
	printf("key_pressed : c_count %i\n", game->c_count); // remove
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
	t_game_info game;

	if (argc == 2) // need to check if map ends with .ber
	{
		is_ber(argv[1]);
		read_map(argv[1], &game);	
	}
	else
	{
		write(1, "Error\nProgramm accepts only 1 argument\n", 39);
		exit(EXIT_FAILURE);
	}
	// printf("map is ok\n"); // remove
	//need to handle cntr c to have no leaks???
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