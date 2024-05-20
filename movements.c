#include "so_long.h"

void	update_window(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	print_sprites(data);
}

int	all_movements(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_UP)
		up_move(key, data);
	else if (key == KEY_D || key == KEY_RIGHT)
		right_move(key, data);
	else if (key == KEY_S || key == KEY_DOWN)
		down_move(key, data);
	else if (key == KEY_A || key == KEY_LEFT)
		left_move(key, data);
	else if (key == KEY_ESC)
		free_data(data);
	ft_printf("%d\n", data->moves);
	return (1);
}
