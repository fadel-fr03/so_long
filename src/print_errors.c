#include "../inc/so_long.h"

void	free_two_dimensional_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
}

void	free_check_map(t_check *c, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(c->map[i]);
	free(c->map);
	c->map = NULL;
}

void	malloc_fail(int type, t_check *c, t_game *game)
{
	if (type == 0)
		ft_printf("Error\nFailed to allocate check structure.\n");
	else if (type == 1)
	{
		free(c);
		ft_printf("Error\nFailed to allocate the check's map.\n");
	}
	else if (type == 2)
	{
		free_check_map(c, game->height);
		free(c);
		ft_printf("Error\nFailed to allocate rows in the check's map\n");
	}
	free_two_dimensional_array(game->map);
	free(game);
	exit (1);
}

void	print_error(int type)
{
	if (type == 0)
		ft_printf("Error\nCouldn't open file.\n");
	else if (type == 1)
		ft_printf("Error\nThe file is empty.\n");
	exit (1);
}
