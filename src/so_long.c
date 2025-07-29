#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\n");
		ft_printf("Usage: ./so_long <map file>\n");
		return (0);
	}
	init_game(&game, argv[1]);
	parse_map(&game);
	check_map(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width * 40,
			game.height * 40, "so_long");
	load_xpm_to_image(&game);
	load_graphics(&game);
	mlx_key_hook(game.win_ptr, key_handler, &game);
	mlx_hook(game.win_ptr, 17, 0, exit_game, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
