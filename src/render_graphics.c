#include "../inc/so_long.h"

static void	draw_player(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->player, width * 40, height * 40);
	game->y = height;
	game->x = width;
}

static void	draw_collectable(t_game *game, int height, int width)
{
	mlx_put_image_to_window(game->mlx_ptr,
		game->win_ptr, game->collectable, width * 40, height * 40);
	game->collectable_count++;
}

void	load_xpm_to_image(t_game *game)
{
	int	i;
	int	j;

	game->ground = mlx_xpm_file_to_image(game->mlx_ptr,
			GROUND, &i, &j);
	if (!game->ground)
	{
		ft_printf("Error loading ground image.\n");
		exit_game(game);
	}
	game->tree = mlx_xpm_file_to_image(game->mlx_ptr, TREE, &i, &j);
	if (!game->tree)
	{
		ft_printf("Error loading tree image.\n");
		exit_game(game);
	}
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &i, &j);
	if (!game->player)
	{
		ft_printf("Error loading player image.\n");
		exit_game(game);
	}
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, EXIT, &i, &j);
	if (!game->exit)
	{
		ft_printf("Error loading exit image.\n");
		exit_game(game);
	}
	game->collectable = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTABLE, &i, &j);
	if (!game->collectable)
	{
		ft_printf("Error loading collectable image.\n");
		exit_game(game);
	}
}

void	load_graphics(t_game *game)
{
	int	height;
	int	width;

	game->collectable_count = 0;
	height = -1;
	while (++height < game->height)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->tree, width * 40, height * 40);
			if (game->map[height][width] == 'C')
				draw_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				draw_player(game, height, width);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->exit, width * 40, height * 40);
			if (game->map[height][width] == '0')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->ground, width * 40, height * 40);
		}
	}
}
