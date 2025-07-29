#include "../inc/so_long.h"

void	init_game(t_game *game, char *file)
{
	game->collectable_count = 0;
	game->collectable = NULL;
	game->exit = NULL;
	game->exit_count = 0;
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->ground = NULL;
	game->height = 0;
	game->map = NULL;
	game->map_name = file;
	game->player = NULL;
	game->player_count = 0;
	game->steps_taken = 0;
	game->tree = NULL;
	game->width = 0;
	game->x = 0;
	game->y = 0;
}
