/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Natalia <Natalia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:57:07 by nandreev          #+#    #+#             */
/*   Updated: 2024/05/28 15:39:37 by Natalia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	flood_fill(char **map, int row, int col, t_game_info *game)
{
	if (game->exit_check == 1 && game->c_count == game->collectibles)
			return(1);
	else if (map[row][col] == 'E')
	{
		game->exit_check = 1;
		return (0);
	}
	else if (map[row][col] == '0' || map[row][col] == 'C' || map[row][col] == 'P')
	{
		if (map[row][col] == 'C')
			game->c_count ++;
		map[row][col] = '+';
		if(flood_fill(map, row + 1, col, game) == 1
			|| flood_fill(map, row - 1, col, game) == 1
			|| flood_fill(map, row, col + 1, game) == 1
			|| flood_fill(map, row, col - 1, game) == 1)
			return (1);
		else
			return(0);
	}
	else
		return(0);
}

// int is_path(char c) {
// 	if (c == '0' || c == 'C')
// 		return (1);
// 	else
// 		return (0);
// }

// int	flood_fill_andrei(char **map, int row, int col)
// {
// 	if (map[row][col] == 'E')
// 	{
// 		return (1);
// 	}
// 	else if (map[row][col] == '0' || map[row][col] == 'C')
// 	{
// 		map[row][col] = '+';
// 		if (is_path(map[row+1][col]) == 1 && flood_fill(map, row + 1, col) == 1
// 			|| is_path(map[row-1][col]) == 1 && flood_fill(map, row - 1, col) == 1
// 			|| is_path(map[row][col+1]) == 1 && flood_fill(map, row, col + 1) == 1
// 			|| is_path(map[row][col-1]) == 1 && flood_fill(map, row, col - 1) == 1)
// 		{
// 			return (1);
// 		}
// 	}
// 	else
// 		return(0);
// }

void	find_p(t_game_info *game, char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row][col] != 'P' && row < game->rows)
	{
		while (col < game->columns && map[row][col] != 'P') //double check if works if p is far right
			col++;
		if (col == game->columns) 
		{
			col = 0;
			row++;
		}
	}
	game->p_position_row = row;
	game->p_position_col = col;
	// flood_fill(map, row, col, game);
	int i = 0; //remove all
	while (i < game->rows) // remove
	{
		printf("map : %s\n", map[i]); // remove
		i++; // remove
	}
	// printf("col: %i\n", game->collectibles);
	// printf("col-check: %i\n", game->c_check);
	// return 0;
	//return (flood_fill(map, row, col, game)); //maybe move out of return
}

int has_valid_path(t_game_info *game, char *map_adress)
{
	char	**map;
	int 	file;
	int		i;

	i = 0;
	map = NULL;
	file = open(map_adress, O_RDWR);
	i = 0;
	map = malloc(sizeof(char *) * (game->rows + 1)); // maybe just rows ???
	if (map == NULL)
		return (0);
	while (i <= game->rows) // when i == rows NULL should be returned
	{
		map[i] = get_next_line(file);
		i ++;
	}
	close(file);
	//remove
	// i = 0;
	// while (i < game->rows)
	// {
	// 	printf("%s\n", map[i]);
	// 	i++;
	// }
	// end remove
	find_p(game, map);
	if (flood_fill(map, game->p_position_row, game->p_position_col, game) == 1)
	{
		free_check_map(map);
		game->c_count = 0;
    	return (1); // if ok
	}
	free_check_map(map);
    return (0); // if not ok
}
