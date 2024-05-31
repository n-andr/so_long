/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/06/01 01:00:21 by Natalia          ###   ########.fr       */
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
New lines
Check every error case with valgrind
*/

void is_rectangular(t_game_info *game)
{
	int	i;

	i = 1;

	if (game->map[0] == NULL)
	{
		write(1, "Error\nEmpty map or memory allocation failed\n", 44);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) == ft_strlen(game->map[i - 1]))
		{
			i++;
		}
		else
		{
			write(1, "Error\nMap is not rectangular\n", 29);
			free_map(game);
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
		col = 0;
		row++;
	}
	return (p_count);
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
		col = 0;
		row++;
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
		free_map(game);
		exit(EXIT_FAILURE);
	}
	if (e_check(game) != 1)
	{
		write(1, "Error\nThe map must contain 1 E\n", 31);
		free_map(game);
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

void	characters_check(t_game_info *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (game->map[row][col] != 'C' 
				&& game->map[row][col] != '1'
				&& game->map[row][col] != '0'
				&& game->map[row][col] != 'E'
				&& game->map[row][col] != 'P')
			{
				write(1, "Error\nForbiden character\n", 25);
				free_map(game);
				exit(EXIT_FAILURE);	
			}	
			col++;
		}
		row++;
	}
}

void	check_map(t_game_info *game)
{
	is_rectangular(game);
	if (game->rows > 25 || game->columns > 45)
	{
		write(1, "Error\nMap is too big\n", 21);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	if (is_closed(game) != 1)
	{
		write(1, "Error\nMap is not closed\n", 24);
		free_map(game);
		exit(EXIT_FAILURE);
	}
	elements_check(game);
	characters_check(game);
	// The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
	if (has_valid_path(game) != 1)
	{
		write(1, "Error\nNo valid path\n", 21);
		free_map(game);
		exit(EXIT_FAILURE);
	}
}

char	*handle_new_line(t_game_info *game, char *line, int row)
{	int	i;

	i = 0;
	if (line == NULL)
		return (NULL);
	if (line[0] == '\n' || row == game->rows - 1)
    {
		game->map[row] = malloc(sizeof(char) * ft_strlen(line) + 1);
		if (game->map[row] == NULL)
			return (NULL);
		ft_strlcpy (game->map[row], line, (ft_strlen(line) + 1));
		return (line);
    }
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	game->map[row] = malloc(sizeof(char) * (i + 1));
	if (game->map[row] == NULL)
		return (NULL);
	ft_strlcpy (game->map[row], line, (i + 1));
	return (line);
}
void	fill_map(char *map_adress, t_game_info *game)
{
	int	file;
	int	i;
	char	*line;

	file = open(map_adress, O_RDONLY);
	i = 0;
	game->map = malloc(sizeof(char *) * (game->rows + 1)); // maybe just rows ???
	if (game->map == NULL)
	{
		write(1, "Error\nReading map failed\n", 25);
		free_map(game);
		close(file);
		exit(EXIT_FAILURE);
	}
	line = get_next_line(file);
	handle_new_line(game, line, i);
	while (line)
	{
		free(line);
		i ++;
		line = get_next_line (file);
		handle_new_line(game, line, i);
	}
	free(line); 
	game->map[game->rows] = NULL;
	close(file);
	check_map(game); // need to check if size of the map fits in the screen (or can move the map)
	game->moves_count = 0;
	return ;
}

int read_map(char *map_adress, t_game_info *game)
{
	int		file;
	char	*line;

	file = open(map_adress, O_RDONLY);
	if (file == -1)
	{
		write(1, "Error\nMap does not exist\n", 25);
		close(file);
		exit(EXIT_FAILURE);
	}
	game->rows = 0;
	line = get_next_line(file);
	if (line == NULL)
	{
		write(1, "Error\nEmpty map or memory allocation failed\n", 44);
		close(file);
		exit(EXIT_FAILURE);
	}
	//???можно убрать всю проверку у маллоков и вот эту строчку с проверкой линии
	// чтобы проверять на нуль поинтер только в is_rectungular и сохранить строчки
	while (line)
	{
		free(line);
		game->rows ++;
		line = get_next_line (file);
	}
	free(line); //check for null? double free?
	close(file);
	fill_map(map_adress, game);
	return (1); // if map is fine
}
