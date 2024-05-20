#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_ESC 65307

# define IMG_HEIGHT	48
# define IMG_WIDTH	48

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/stat.h>
# include "mlx/mlx.h"
# include "Libft/Headers/libft.h"

# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define FLOOR '0'
# define WALL '1'

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

typedef struct s_map
{
	char			**mtx;
	int				row;
	int				col;
	int				player_version;
	t_coordinates	player;
	t_coordinates	exit;
}	t_map;

typedef struct s_data
{
	t_map	map;
	void	*mlx;
	void	*window;
	void	*player[4];
	void	*wall;
	void	*exit;
	void	*collectible;
	void	*floor;
	int		count_coll;
	int		moves;
	int		altezza_sprite;
	int		larghezza_sprite;
}	t_data;
//matrix functions
char	**read_map(char *str);
int		check_map(t_map *map);
int		valid_path(t_map *map);
//item positions
void	all_positions(t_map *map);
//Various allocations
int		map_alloc(char *file, t_map *map);
int		init_data(t_data *data, char *file);
//putting images to window
void	sprite_player(t_data *data);
void	items_sprite(t_data *data);
void	print_sprites(t_data *data);
//movements
void	update_window(t_data *data);
void	up_move(int key, t_data *data);
void	right_move(int key, t_data *data);
void	down_move(int key, t_data *data);
void	left_move(int key, t_data *data);
int		all_movements(int key, t_data *data);
//functions utils
int		check_char(char **mtx, int c);
int		check_file(char *file);
//finish game
void	free_images(t_data *data);
int		free_data(t_data *data);

#endif