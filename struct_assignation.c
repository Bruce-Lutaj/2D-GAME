#include "so_long.h"

int	map_alloc(char *file, t_map *map)
{
	int	c;

	c = check_char(map->mtx, 'C');
	map->mtx = read_map(file);
	if (!map->mtx)
		return (0);
	map->row = ft_rowlen(map->mtx);
	map->col = ft_colen(map->mtx);
	map->player_version = 0;
	if (!check_map(map))
	{
		free_mtx(map->mtx);
		return (0);
	}
	all_positions(map);
	if (!valid_path(map))
	{
		free_mtx(map->mtx);
		return (0);
	}
	return (1);
}

int	init_data(t_data *data, char *file)
{
	data->altezza_sprite = 48;
	data->larghezza_sprite = 48;
	data->moves = 0;
	if (!map_alloc(file, &data->map))
		return (0);
	data->mlx = mlx_init();
	data->count_coll = check_char(data->map.mtx, 'C');
	data->window = mlx_new_window(data->mlx, ft_colen(data->map.mtx) * 48,
			ft_rowlen(data->map.mtx) * 48, "So_Long");
	items_sprite(data);
	return (1);
}
