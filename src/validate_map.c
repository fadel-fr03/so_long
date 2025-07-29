#include "../inc/so_long.h"

static	t_check	*init_check(t_game *game)
{
	int		i;
	int		j;
	t_check	*c;

	c = (t_check *)malloc(sizeof(t_check));
	if (!c)
		malloc_fail(0, NULL, game);
	c->map = (int **)malloc(sizeof(int *) * game->height);
	if (!c->map)
		malloc_fail(1, c, game);
	i = -1;
	while (++i < game->height)
	{
		c->map[i] = (int *)malloc(sizeof(int) * game->width);
		if (!c->map[i])
			malloc_fail(2, c, game);
	}
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			c->map[i][j] = 0;
	}
	return (c);
}

static void	check_paths_util(t_check *c, t_game *game, int x, int y)
{
	if (c->collectable_count == 0)
		return ;
	if (c->map[y][x] == 0 && game->map[y][x] != '1')
	{
		c->map[y][x] = 1;
		if (game->map[y][x] == 'C' || game->map[y][x] == 'E')
			c->collectable_count--;
		if (game->map[y][x] == 'E')
			return ;
		check_paths_util(c, game, x + 1, y);
		check_paths_util(c, game, x - 1, y);
		check_paths_util(c, game, x, y + 1);
		check_paths_util(c, game, x, y - 1);
	}
}

static void	check_paths(t_game *game)
{
	t_check	*c;

	c = init_check(game);
	c->collectable_count = game->collectable_count + game->exit_count;
	check_paths_util(c, game, game->x, game->y);
	if (c->collectable_count != 0)
	{
		free_check_map(c, game->height);
		free(c);
		ft_printf("Error\nMap is imposible to navigate.\n");
		exit_game(game);
	}
	free_check_map(c, game->height);
	free(c);
}

static void	get_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	if (game->height == 0 || game->width == 0)
	{
		free_two_dimensional_array(game->map);
		ft_printf("Error\nMap is invalid.\n");
		exit(1);
	}
	check_map_name(game);
	check_map_wall(game);
	check_map_contents(game);
	check_asset_count(game);
	get_player_pos(game);
	check_paths(game);
}
