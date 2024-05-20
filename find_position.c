#include "so_long.h"

t_coordinates	item_pos(int x, int y)
{
	t_coordinates	pos;

	pos.x = x;
	pos.y = y;
	return (pos);
}

void	all_positions(t_map *map)
{
	int		x;
	int		y;

	x = -1;
	while (map->mtx[++x])
	{
		y = -1;
		while (map->mtx[x][++y])
		{
			if (map->mtx[x][y] == 'P')
				map->player = item_pos(x, y);
			else if (map->mtx[x][y] == 'E')
				map->exit = item_pos(x, y);
		}
	}
}
