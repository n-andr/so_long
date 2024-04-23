/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:23:28 by nandreev          #+#    #+#             */
/*   Updated: 2024/04/23 16:49:31 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangular(char *map)
{
    write(1, "Error\nMap is not rectangular\n", 29);
    exit(EXIT_FAILURE);
}

int is_closed(char *map)
{
    write(1, "Error\nMap is not closed/surrounded by walls\n", 44);
    exit(EXIT_FAILURE);
}

int has_valid_path(char *map)
{
    write(1, "Error\nNo valid path\n", 21);
    exit(EXIT_FAILURE);
}

int	fill_map(char *map, int lines, t_game_info *game)
{
	int	file;
	int	i;

	file = open(map, O_RDWR);
	i = 0;
	game->map = malloc(sizeof(char *) * (lines + 1)); // maybe lines ???
	if (game->map == NULL)
		return (NULL);
	while (i <= lines) // when i == lines NULL should be returned
	{
		game->map[i] = get_next_line(file);
		i ++;
	}
	i = 0;
	while (i <= lines)
	{
		printf("line %d : %s", i, game->map[i]);
		i ++;
	}
	return (1);
	
}

int read_map(char *map, t_game_info *game)
{
	int		file;
	char	*line;
	int		count_lines;

	file = open(map, O_RDWR);
	if (file == -1)
	{
		write(1, "Error\nMap does not exist\n", 25);
		exit(EXIT_FAILURE);
	}
	count_lines = 0;
	line = get_next_line(file);
	if (line == NULL)
	{
		write(1, "Error\nMap is wrong\n", 19);
		exit(EXIT_FAILURE);
	}
	while (line)
	{
		free(line);
		count_lines ++;
		line = get_next_line (file);
	}
	free(line); //check for null? double free?
	fill_map(map, count_lines, game);
	close(file);

	// is_rectangular(map);
	// is_closed(map);
	// has_valid_path(map);
	return (1); // if map is fine
}
