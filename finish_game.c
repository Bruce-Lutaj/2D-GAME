#include "so_long.h"

void	free_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player[0]);
	mlx_destroy_image(data->mlx, data->player[1]);
	mlx_destroy_image(data->mlx, data->player[2]);
	mlx_destroy_image(data->mlx, data->player[3]);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->floor);
}

int	free_data(t_data *data)
{
	free_images(data);
	free_mtx(data->map.mtx);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
