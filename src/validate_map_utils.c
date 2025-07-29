#include "../inc/so_long.h"

void	check_map_name(t_game *game)
{
	int		len;
	char	*extension;

	extension = ".ber";
	len = ft_strlen(game->map_name);
	if (len < 4 || ft_strncmp(game->map_name + len - 4, extension, 4) != 0)
	{
		free_two_dimensional_array(game->map);
		ft_printf("Error\nWrong file extension.\n");
		exit(1);
	}
}

void	check_map_wall(t_game *game)
{
	int		i;
	bool	missing_wall;

	i = 0;
	missing_wall = false;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			missing_wall = true;
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			missing_wall = true;
		i++;
	}
	if (missing_wall)
	{
		free_two_dimensional_array(game->map);
		ft_printf("Error\nMissing walls on map outline.\n");
		exit (1);
	}
}

void	check_map_contents(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != 'P'
				&& game->map[i][j] != 'E' && game->map[i][j] != '0'
				&& game->map[i][j] != 'C')
			{
				free_two_dimensional_array(game->map);
				ft_printf("Error\nFound undefined characters.\n");
				exit (1);
			}
			j++;
		}
		i++;
	}
}

static void	free_and_print(t_game *game)
{
	free_two_dimensional_array(game->map);
	ft_printf("Error\nMap should have one player,");
	ft_printf(" one exit and at least one collectables.\n");
}

void	check_asset_count(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->player_count++;
			if (game->map[i][j] == 'C')
				game->collectable_count++;
			if (game->map[i][j] == 'E')
				game->exit_count++;
		}
	}
	if (game->player_count != 1 || game->exit_count != 1
		|| game->collectable_count < 1)
	{
		free_and_print(game);
		exit (1);
	}
}
