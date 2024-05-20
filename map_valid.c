#include "so_long.h"

void	flood_fill(char **map, int row, int col)
{
	if (map[row][col] == '1' || map[row][col] == 'X')
		return ;
	map[row][col] = 'X';
	flood_fill(map, row + 1, col);
	flood_fill(map, row - 1, col);
	flood_fill(map, row, col + 1);
	flood_fill(map, row, col - 1);
}

int	read_copy(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!mtx)
		return (0);
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] != '1' && mtx[i][j] != 'X' && mtx[i][j] != '0')
				return (ft_printf("Unplayable"), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_path(t_map *map)
{
	char	**copy;

	copy = copy_mtx(map->mtx);
	flood_fill(copy, map->player.x, map->player.y);
	if (!read_copy(copy))
		return (free_mtx(copy), 0);
	free_mtx(copy);
	return (1);
}
