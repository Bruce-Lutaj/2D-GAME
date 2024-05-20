#include "so_long.h"

int	check_move(int key, t_data *data)
{
	if (key == KEY_W || key == KEY_UP)
	{
		if (data->map.mtx[data->map.player.x - 1]
			[data->map.player.y] == '1')
			return (0);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		if (data->map.mtx[data->map.player.x + 1]
			[data->map.player.y] == '1')
			return (0);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		if (data->map.mtx[data->map.player.x]
			[data->map.player.y - 1] == '1')
			return (0);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		if (data->map.mtx[data->map.player.x]
			[data->map.player.y + 1] == '1')
			return (0);
	}
	return (1);
}

void	up_move(int key, t_data *data)
{
	if ((key == KEY_W || key == KEY_UP)
		&& check_move(key, data))
	{
		data->map.mtx[data->map.player.x][data->map.player.y] = '0';
		if (data->map.mtx[data->map.player.x - 1][data->map.player.y] == 'C')
			data->count_coll--;
		if (data->count_coll >= 1)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = '0';
		else if (data->count_coll == 0)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = 'E';
		if (data->map.mtx[data->map.player.x - 1]
			[data->map.player.y] == 'E' && data->count_coll == 0)
			free_data(data);
		data->map.player = (t_coordinates){data->map.player.x - 1,
			data->map.player.y};
		data->map.player_version = 0;
		data->map.mtx[data->map.player.x][data->map.player.y] = 'P';
		data->moves++;
		update_window(data);
	}
}

void	right_move(int key, t_data *data)
{
	if ((key == KEY_D || key == KEY_RIGHT)
		&& check_move(key, data))
	{
		data->map.mtx[data->map.player.x]
		[data->map.player.y] = '0';
		if (data->map.mtx[data->map.player.x][data->map.player.y + 1] == 'C')
			data->count_coll--;
		if (data->count_coll >= 1)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = '0';
		else if (data->count_coll == 0)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = 'E';
		if (data->map.mtx[data->map.player.x]
			[data->map.player.y + 1] == 'E' && data->count_coll == 0)
			free_data(data);
		data->map.player = (t_coordinates){data->map.player.x,
			data->map.player.y + 1};
		data->map.player_version = 1;
		data->map.mtx[data->map.player.x][data->map.player.y] = 'P';
		data->moves++;
		update_window(data);
	}
}

void	down_move(int key, t_data *data)
{
	if ((key == KEY_S || key == KEY_DOWN)
		&& check_move(key, data))
	{
		data->map.mtx[data->map.player.x]
		[data->map.player.y] = '0';
		if (data->map.mtx[data->map.player.x + 1][data->map.player.y] == 'C')
			data->count_coll--;
		if (data->count_coll >= 1)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = '0';
		else if (data->count_coll == 0)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = 'E';
		if (data->map.mtx[data->map.player.x + 1]
			[data->map.player.y] == 'E' && data->count_coll == 0)
			free_data(data);
		data->map.player = (t_coordinates){data->map.player.x + 1,
			data->map.player.y};
		data->map.player_version = 2;
		data->map.mtx[data->map.player.x][data->map.player.y] = 'P';
		data->moves++;
		update_window(data);
	}
}

void	left_move(int key, t_data *data)
{
	if ((key == KEY_A || key == KEY_LEFT)
		&& check_move(key, data))
	{
		data->map.mtx[data->map.player.x]
		[data->map.player.y] = '0';
		if (data->map.mtx[data->map.player.x][data->map.player.y - 1] == 'C')
			data->count_coll--;
		if (data->count_coll >= 1)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = '0';
		else if (data->count_coll == 0)
			data->map.mtx[data->map.exit.x][data->map.exit.y] = 'E';
		if (data->map.mtx[data->map.player.x]
			[data->map.player.y - 1] == 'E' && data->count_coll == 0)
			free_data(data);
		data->map.player = (t_coordinates){data->map.player.x,
			data->map.player.y - 1};
		data->map.player_version = 3;
		data->map.mtx[data->map.player.x][data->map.player.y] = 'P';
		data->moves++;
		update_window(data);
	}
}
