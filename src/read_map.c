/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/24 23:24:23 by Natalia          ###   ########.fr       */
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
			while (game->map[i][k] == '\0')
			{
				if (game->map[i][k] == '1')
					k ++;
				else
					return(1);
				k = 0;
			}
			i ++;
		}
		else if ((game->map[i][0] == 1) && (game->map[i][game->columns - 1] == 1)
				&& i != 0 && i != (game->rows - 1))
			i ++;
		else
			return(1);
	}
}

int has_valid_path(t_game_info *game)
{
    write(1, "Error\nNo valid path\n", 21);
	free_game(game);
    exit(EXIT_FAILURE);
}
void	check_map(t_game_info *game)
{
	is_rectangular(game);
	if (is_closed(game) == 1)
	{
		write(1, "Error\nMap is not closed\n", 24);
		free_game(game);
		exit(EXIT_FAILURE);
	}
	has_valid_path(game);
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
	check_map(game);
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
