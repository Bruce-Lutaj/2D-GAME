#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		exit(EXIT_SUCCESS);
	}
	data = (t_data){0};
	if (!init_data(&data, av[1]))
		return (-1);
	mlx_hook(data.window, 2, (1L << 0), &all_movements, &data);
	mlx_hook(data.window, 17, 1L << 17, &free_data, &data);
	if (data.count_coll >= 1)
		data.map.mtx[data.map.exit.x][data.map.exit.y] = '0';
	print_sprites(&data);
	mlx_loop(data.mlx);
}
