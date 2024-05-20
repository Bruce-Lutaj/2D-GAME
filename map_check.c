#include "so_long.h"

int	valid_rows(char **mtx, int row)
{
	int	i;

	i = 0;
	if (!mtx)
		return (0);
	while (i < row && mtx[i + 1])
	{
		if (!len_cmp(mtx[i], mtx[i + 1]))
			return (ft_printf("Invalid shape"), 0);
		i++;
	}
	return (1);
}

int	check_walls(char **mtx, int row, int col)
{
	int	i;
	int	j;

	i = 0;
	if (!mtx || row == col || col < 3 || row < 3 || col > 50 || row > 30
		|| !valid_rows(mtx, row))
		return (ft_printf("Wrong shape"), 0);
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
			{
				if (mtx[i][j] != '1')
					return (ft_printf("invalid walls"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_char(char **mtx, int c)
{
	int	x;
	int	y;
	int	n;

	x = -1;
	y = -1;
	n = 0;
	while (mtx && mtx[++x])
	{
		y = -1;
		while (mtx && mtx[x][++y])
		{
			if (mtx[x][y] == c)
				n++;
		}
	}
	return (n);
}

int	check_map(t_map *map)
{
	if (check_walls(map->mtx, map->row, map->col))
	{
		if ((check_char(map->mtx, 'P') == 1)
			&& (check_char(map->mtx, 'E') == 1)
			&& (check_char(map->mtx, 'C') >= 1))
			return (1);
		else
			return (ft_printf("Invalid items"), 0);
	}
	else
		return (0);
}
