#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../get_next_line/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

# define COLLECTABLE "./textures/collectable.xpm"
# define GROUND "./textures/ground.xpm"
# define EXIT "./textures/exit.xpm"
# define PLAYER "./textures/player.xpm"
# define TREE "./textures/tree.xpm"

# ifdef _WIN32
#  define W 0x57
#  define A 0x41
#  define S 0x53
#  define D 0x44
#  define ESC 0x1B
# elif defined(__linux__)
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define ESC 65307
#  define UP 65362
#  define DOWN 65364
#  define LEFT 65361
#  define RIGHT 65363
# endif

typedef struct s_check
{
	int		collectable_count;
	int		**map;
}	t_check;

typedef struct s_game
{
	int		height;
	int		width;
	int		player_count;
	int		exit_count;
	int		collectable_count;
	int		x;
	int		y;
	int		steps_taken;
	char	**map;
	char	*map_name;
	void	*ground;
	void	*tree;
	void	*player;
	void	*exit;
	void	*collectable;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_game;

/*		Free everything and exit game		*/
int		exit_game(t_game *game);

/*		Initialize the t_game structure		*/
void	init_game(t_game *game, char *file);

/*		Handle player movement when keys are pressed		*/
int		key_handler(int keycode, t_game *game);

/*		Read the given map		*/
int		parse_map(t_game *game);

/*		Error handling		*/
void	free_two_dimensional_array(char **array);
void	free_check_map(t_check *c, int height);
void	malloc_fail(int type, t_check *c, t_game *game);
void	print_error(int type);

/*		Graphics Rendering		*/
void	load_xpm_to_image(t_game *game);
void	load_graphics(t_game *game);

/*		Checking if the map is valid	*/
void	check_map_name(t_game *game);
void	check_map_wall(t_game *game);
void	check_map_contents(t_game *game);
void	check_asset_count(t_game *game);
void	check_map(t_game *game);

#endif