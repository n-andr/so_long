#include "../so_long.h"

int	flood_fill(char **map, int row, int col)
{
	if (map[row][col] == 'E')
	{
		return (1);
	}
	else if (map[row][col] == '0' || map[row][col] == 'C')
	{
		map[row][col] = '+';
		if (flood_fill(map, row + 1, col) == 1
			|| flood_fill(map, row - 1, col) == 1
			|| flood_fill(map, row, col + 1) == 1
			|| flood_fill(map, row, col - 1) == 1)
		{
			return (1);
		}
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

int	find_p(char **map)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (map[row][col] != 'P')
	{
		while (col < ft_strlen(map[row]) && (map[row][col] != 'P'))
			col ++;
		row ++;
	}
	return (flood_fill(map, row, col));
}

int has_valid_path(t_game_info *game)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc(game->rows, sizeof(char));
	while (game->map[i])
	{
		map[i] = ft_calloc(game->rows, sizeof(char));
		ft_strlcpy(map[i], game->map[i], game->columns + 1);
		i++;
	}
	find_p(map);
	
	free_check_map(map);
    return (0); // if not ok
}