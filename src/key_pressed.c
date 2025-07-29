#include "../inc/so_long.h"

static int	move(t_game *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectable_count != 0)
			return (0);
		ft_printf("CONGRATULATIONS, YOU WON!\n");
		ft_printf("It took you %d moves to win.", game->steps_taken);
		ft_printf("Can you beat this score!!\n");
		exit_game(game);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->steps_taken++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x = i;
		game->y = j;
		game->collectable_count--;
		game->steps_taken++;
	}
	return (1);
}

static int	keyboard_up_down(t_game *game, int movement)
{
	int	i;
	int	j;
	int	old_y;

	i = game->x;
	j = game->y;
	old_y = game->y;
	if (movement == W || movement == UP)
		j--;
	else
		j++;
	if (game->map[j][i] == '1')
		return (0);
	if (!move(game, i, j))
		return (0);
	game->map[old_y][i] = '0';
	ft_printf("Steps Taken: %i\n", game->steps_taken);
	return (1);
}

static int	keyboard_left_right(t_game *game, int movement)
{
	int	i;
	int	j;
	int	old_x;

	i = game->x;
	j = game->y;
	old_x = game->x;
	if (movement == A || movement == LEFT)
		i--;
	else
		i++;
	if (game->map[j][i] == '1')
		return (0);
	if (!move(game, i, j))
		return (0);
	game->map[j][old_x] = '0';
	ft_printf("Steps Taken: %i\n", game->steps_taken);
	return (1);
}

int	key_handler(int keycode, t_game *game)
{
	int	moved;

	if (keycode == ESC)
	{
		ft_printf("Exited game before finishing level.\n");
		exit_game(game);
	}
	if (keycode == W || keycode == UP)
		moved = keyboard_up_down(game, keycode);
	if (keycode == S || keycode == DOWN)
		moved = keyboard_up_down(game, keycode);
	if (keycode == A || keycode == LEFT)
		moved = keyboard_left_right(game, keycode);
	if (keycode == D || keycode == RIGHT)
		moved = keyboard_left_right(game, keycode);
	if (moved)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		load_graphics(game);
	}
	return (0);
}
