#include "../inc/so_long.h"

static int	get_width(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	add_new_row(t_game *game, char *line)
{
	char	**temp;
	int		i;

	i = 0;
	game->height++;
	temp = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!temp)
	{
		free(line);
		return (0);
	}
	temp[game->height] = NULL;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	free(game->map);
	temp[i] = ft_strdup(line);
	game->map = temp;
	return (1);
}

static	void	check_rectangular(t_game *game)
{
	int	len;
	int	new_len;
	int	i;

	len = get_width(game->map[0]);
	i = 0;
	while (game->map[i])
	{
		new_len = get_width(game->map[i]);
		if (new_len != len)
		{
			free_two_dimensional_array(game->map);
			ft_printf("Error\nThe map should be rectangular.\n");
			exit (1);
		}
		i++;
	}
}

int	parse_map(t_game *game)
{
	char	*line;
	int		fd;
	int		empty;

	fd = open(game->map_name, O_RDONLY);
	if (fd == -1)
		print_error(0);
	empty = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line || !add_new_row(game, line))
			break ;
		empty = 0;
		free (line);
	}
	close(fd);
	if (empty)
		print_error(1);
	if (game->map[0])
	{
		game->width = get_width(game->map[0]);
		check_rectangular(game);
	}
	return (1);
}
