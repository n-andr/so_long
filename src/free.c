#include "../so_long.h"

void	free_game(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map[i]) //need to free one more that is already null?
	{
		//printf("line %d : %s", i, game->map[i]);
		free (game->map[i]);
		i ++;
	}
	free (game->map);
}