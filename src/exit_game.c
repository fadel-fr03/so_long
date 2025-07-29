#include "../inc/so_long.h"

int	exit_game(t_game *game)
{
	if (game->collectable)
		mlx_destroy_image(game->mlx_ptr, game->collectable);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->ground)
		mlx_destroy_image(game->mlx_ptr, game->ground);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->tree)
		mlx_destroy_image(game->mlx_ptr, game->tree);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->map)
		free_two_dimensional_array(game->map);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
	return (0);
}
