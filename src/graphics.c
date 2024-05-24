#include "../so_long.h"

// void	display_textures(t_game_info *game)
// {

// }

void	open_img(t_game_info *game)
{
	game->img_height = IMG_HEIGHT;
	game->img_width = IMG_WIDTH;
	//game->current_frame = 0;
	game->textures.player = mlx_xpm_file_to_image(game->mlx, \
	"assets/dckFall-32x32_.xpm",game->img_width, game->img_height);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx, \
	"assets/potion1.xpm",game->img_width, game->img_height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, \
	"assets/mirror.xpm",game->img_width, game->img_height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, \
	"assets/volcanoe_tiles_border.xpm",game->img_width, game->img_height);
	game->textures.background = mlx_xpm_file_to_image(game->mlx, \
	"assets/volcanoe_tiles_bg.xpm",game->img_width, game->img_height);
	if (game->textures.player == NULL || game->textures.background == NULL
		|| game->textures.collectible == NULL || game->textures.exit == NULL
		|| game->textures.wall == NULL)
		write(1, "error: open images\n", 19);
}

void	load_row(t_game_info *game, int i)
{
	int	k;

	k = 0;
	while (game->map[i][k])
	{
		if (game->map[i][k] == '1')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.wall, k * 32, i * 32);
		else if (game->map[i][k] == '0')
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.background, k * 32, i * 32);
		else if (game->map[i][k] == 'C')
		{
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.background, k * 32, i * 32);
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.collectible, k * 32, i * 32);
		}
		else if (game->map[i][k] == 'P')
		{
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.background, k * 32, i * 32);
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.player, k * 32, i * 32);
		}
		else if (game->map[i][k] == 'E')
		{
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.background, k * 32, i * 32);
			mlx_put_image_to_window(game->mlx, game->window, \
			game->textures.exit, k * 32, i * 32);
		}
		k++;
	}
	//maybe use mlx_pixel_put to fill all the bg???
}
void	load_map_graphics(t_game_info *game)
{
	int	i;

	i = 0;
	while (game->map[i] != NULL)
	{
		//maybe load bg here for everything in every row
		load_row(game, i);
		i++;
	}
}
