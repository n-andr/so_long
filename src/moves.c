#include "../so_long.h"

/*
key == 119 - W
key == 115  - S
key == 100 - D
key == 97 - A

based on ASCII lowercase
*/
void	move_up(t_game_info *game, int row, int col)
{
	if (game->map[row - 1][col] == '0')
	{
		game->map[row][col] = '0';
		game->map[row - 1][col] = 'P';
	}
	else if (game->map[row - 1][col] == '1')
		return;
	else if (game->map[row - 1][col] == 'C')
	{
		game->map[row][col] = '0';
		game->map[row - 1][col] = 'P';
		game->c_count ++;
	}
	else if (game->map[row - 1][col] == 'E' && game->c_count == game->collectibles)
	{
		count_moves(game);
		//success!
		close_game(game);
	}
	else if (game->map[row - 1][col] == 'E' && game->c_count != game->collectibles)
		return;
	count_moves(game);
	load_map_graphics(game);
}

void	move_down(t_game_info *game, int row, int col)
{
	if (game->map[row + 1][col] == '0')
	{
		game->map[row][col] = '0';
		game->map[row + 1][col] = 'P';
	}
	else if (game->map[row + 1][col] == '1')
		return;
	else if (game->map[row + 1][col] == 'C')
	{
		game->map[row][col] = '0';
		game->map[row + 1][col] = 'P';
		game->c_count ++;
	}
	else if (game->map[row + 1][col] == 'E' && game->c_count == game->collectibles)
	{
		count_moves(game);
		//success!
		close_game(game);
	}
	else if (game->map[row + 1][col] == 'E' && game->c_count != game->collectibles)
		return;
	count_moves(game);
}

void	move_left(t_game_info *game, int row, int col)
{
	if (game->map[row][col - 1] == '0')
	{
		game->map[row][col] = '0';
		game->map[row][col - 1] = 'P';
	}
	else if (game->map[row][col - 1] == '1')
		return;
	else if (game->map[row][col - 1] == 'C')
	{
		game->map[row][col] = '0';
		game->map[row][col - 1] = 'P';
		game->c_count ++;
	}
	else if (game->map[row][col - 1] == 'E' && game->c_count == game->collectibles)
	{
		count_moves(game);
		//success!
		close_game(game);
	}
	else if (game->map[row][col - 1] == 'E' && game->c_count != game->collectibles)
		return;
	count_moves(game);
}

void	move_right(t_game_info *game, int row, int col)
{
	if (game->map[row][col + 1] == '0')
	{
		game->map[row][col] = '0';
		game->map[row][col + 1] = 'P';
		count_moves(game);
	}
	else if (game->map[row][col + 1] == '1')
		return;
	else if (game->map[row][col + 1] == 'C')
	{
		game->map[row][col] = '0';
		game->map[row][col + 1] = 'P';
		count_moves(game);
	}
	else if (game->map[row][col + 1] == 'E' && game->c_count == game->collectibles)
	{
		count_moves(game);
		//success!
		close_game(game);
	}
	else if (game->map[row][col + 1] == 'E' && game->c_count != game->collectibles)
		return;
}

void	move_p(t_game_info *game, int key)
{
	find_p(game, game->map);
	if (key == 119)
	{
		move_up(game, game->p_position_row, game->p_position_col);
	}
	else if (key == 115)
	{
		move_down(game, game->p_position_row, game->p_position_col);
	}
	else if (key == 100)
	{
		move_right(game, game->p_position_row, game->p_position_col);
	}
	else if (key == 97)
	{
		move_left(game, game->p_position_row, game->p_position_col);
	}
}

