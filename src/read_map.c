/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/26 17:50:18 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			free_game(game);
    		exit(EXIT_FAILURE);
		}
		game->columns = ft_strlen(game->map[0]);
	}
	printf("map is rectangular\n"); // remove
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
	int e_count;

	row = 0;
	e_count = 0;
	while (row < game->rows)
	{
		col = 0;
		while (col < game->columns)
		{
			if (game->map[row][col] == 'C')
				e_count ++;
			col++;
		}
		row++;
	}
	game->collectibles = e_count;
	game->c_check = 0;
	printf("collectables: %i", game->collectibles);
	return(e_count);
}

void	elements_check(t_game_info *game)
{
	if (p_check(game) != 1)
	{
		write(1, "Error\nThe map must contain 1 P\n", 31);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	if (e_check(game) != 1)
	{
		write(1, "Error\nThe map must contain 1 E\n", 31);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	if (c_check(game) < 1)
	{
		write(1, "Error\nThe map must contain 1 C\n", 31);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	return ;

}
void	check_map(t_game_info *game, char *map_adress)
{
		printf("check map\n"); // remove

	is_rectangular(game);
	if (is_closed(game) != 1)
	{
		write(1, "Error\nMap is not closed\n", 24);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	elements_check(game);
	// The map must contain 1 exit, at least 1 collectible, and 1 starting position to be valid.
	if (has_valid_path(game, map_adress) != 1)
	{
		write(1, "Error\nNo valid path\n", 21);
		free_game(game);
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
	check_map(game, map);
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
