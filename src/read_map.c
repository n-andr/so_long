/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/27 14:43:58 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Is not too big to play
Has to be rectangular
Has to be surrounded by walls
No empty lines anywhere
Has to have a valid path to every coin and exit
No other characters besides 1, 0, C, E, P
Only one player and exit
You have to handle the case if the coin is blocked by the exit
Empty map case
Invalid extension (only .ber allowed)
Map does not exist
No arguments or to many arguments
Check every error case with valgrind
*/

void is_rectangular(t_game_info *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) == ft_strlen(game->map[i - 1]))
		{
			i++;
		}
		else
		{
			write(1, "Error\nMap is not rectangular\n", 29);
			(game);
    		exit(EXIT_FAILURE);
		}
		game->columns = ft_strlen(game->map[0]);
	}
	// printf("map is rectangular\n") ; // remove
}

int is_closed(t_game_info *game)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (game->map[i])
	{
		if (i == 0 || i == (game->rows - 1))
		{
			while (game->map[i][k] != '\0')
			{
				if (game->map[i][k] == '1')
					k ++;
				else
					return(0);
			}
			k = 0;
			i ++;
		}
		else if ((game->map[i][0] == '1') && (game->map[i][game->columns - 1] == '1')
				&& i != 0 && i != (game->rows - 1))
			i ++;
		else
			return(0);
	}
	return(1);
}

int	p_check(t_game_info *game)
{
	int	row;
	int	col;
	int p_count;

	row = 0;
	col = 0;
	p_count = 0;
	while (row < game->rows)
	{
		while (col < game->columns)
			{
				if (game->map[row][col] == 'P')
					p_count ++;
				col++;
			}
		if (col == game->columns) 
		{
			col = 0;
			row++;
		}
	}
	return(p_count);
}

int	e_check(t_game_info *game)
{
	int	row;
	int	col;
	int e_count;

	row = 0;
	col = 0;
	e_count = 0;
	while (row < game->rows)
	{
		while (col < game->columns)
			{
				if (game->map[row][col] == 'E')
					e_count ++;
				col++;
			}
		if (col == game->columns) 
		{
			col = 0;
			row++;
		}
	}
	game->exit_check = 0;
	return(e_count);
}

int	c_check(t_game_info *game)
{
	int	row;
	int	col;

	row = 0;
	game->c_count = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (game->map[row][col] == 'C')
				game->c_count ++;
			col++;
		}
		row++;
	}
	game->collectibles = game->c_count;
	game->c_count = 0;
	return(game->collectibles);
}

void	elements_check(t_game_info *game)
{
	if (p_check(game) != 1)
	{
		write(1, "Error\nThe map must contain 1 P\n", 31);
		(game);
		exit(EXIT_FAILURE);
	}
	if (e_check(game) != 1)
	{
		write(1, "Error\nThe map must contain 1 E\n", 31);
		(game);
		exit(EXIT_FAILURE);
	}
	if (c_check(game) < 1)
	{
		write(1, "Error\nThe map must contain min 1 C\n", 36);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	// need to check that only allowed characters are here
	return ;

}
void	check_map(t_game_info *game, char *map_adress)
{
		printf("check map\n"); // remove

	is_rectangular(game);
	if (is_closed(game) != 1)
	{
		write(1, "Error\nMap is not closed\n", 24);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	elements_check(game);
	// The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
	if (has_valid_path(game, map_adress) != 1)
	{
		write(1, "Error\nNo valid path\n", 21);
		free_map(game);
		exit(EXIT_FAILURE);
	}
}
void	fill_map(char *map, t_game_info *game)
{
	int	file;
	int	i;

	file = open(map, O_RDWR);
	i = 0;
	game->map = malloc(sizeof(char *) * (game->rows + 1)); // maybe just rows ???
	if (game->map == NULL)
		return ;
	while (i <= game->rows) // when i == rows NULL should be returned
	{
		game->map[i] = get_next_line(file);
		i ++;
	}
	close(file);
	check_map(game, map); // need to check if size of the map fits in the screen (or can move the map)
	game->moves_count = 0;
	return ;
}

int read_map(char *map, t_game_info *game)
{
	int		file;
	char	*line;

	file = open(map, O_RDWR);
	if (file == -1)
	{
		write(1, "Error\nMap does not exist\n", 25);
		exit(EXIT_FAILURE);
	}
	game->rows = 0;
	line = get_next_line(file);
	if (line == NULL)
	{
		write(1, "Error\nMap is wrong\n", 19);
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		free(line);
		game->rows ++;
		line = get_next_line (file);
	}
	free(line); //check for null? double free?
	close(file);
	fill_map(map, game);
	return (1); // if map is fine
}
