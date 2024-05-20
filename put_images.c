#include "so_long.h"

void	sprite_player(t_data *data)
{
	data->player[0] = mlx_xpm_file_to_image(data->mlx,
			"textures/player_up.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
	data->player[1] = mlx_xpm_file_to_image(data->mlx,
			"textures/player_right.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
	data->player[2] = mlx_xpm_file_to_image(data->mlx,
			"textures/player_down.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
	data->player[3] = mlx_xpm_file_to_image(data->mlx,
			"textures/player_left.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
}

void	items_sprite(t_data *data)
{
	sprite_player(data);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"textures/wall.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"textures/grass.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/collectible.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"textures/exit.xpm",
			&(data->altezza_sprite), &(data->larghezza_sprite));
}

void	images_on_window(t_data *data, int rows, int cols)
{
	if (data->map.mtx[rows][cols] == PLAYER)
		mlx_put_image_to_window(data->mlx, data->window,
			data->player[data->map.player_version],
			48 * cols, 48 * rows);
	else if (data->map.mtx[rows][cols] == EXIT)
		mlx_put_image_to_window(data->mlx, data->window,
			data->exit, 48 * cols, 48 * rows);
	else if (data->map.mtx[rows][cols] == FLOOR)
		mlx_put_image_to_window(data->mlx, data->window,
			data->floor, 48 * cols, 48 * rows);
	else if (data->map.mtx[rows][cols] == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx, data->window,
			data->collectible, 48 * cols, 48 * rows);
	else if (data->map.mtx[rows][cols] == WALL)
		mlx_put_image_to_window(data->mlx, data->window,
			data->wall, 48 * cols, 48 * rows);
}

void	print_sprites(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < ft_rowlen(data->map.mtx))
	{
		y = -1;
		while (++y < ft_colen(data->map.mtx))
		{
			images_on_window(data, x, y);
		}
	}
}
