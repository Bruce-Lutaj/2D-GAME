#include "so_long.h"

int	valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'E' || c == 'C' || c == 'P')
		return (1);
	return (0);
}

int	check_file(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i >= 5)
	{
		i -= 4;
		if ((file[i] != '.') || (file[i + 1] != 'b') || (file[i + 2] != 'e')
			|| (file[i + 3] != 'r'))
			return (ft_printf("File error\n"), 0);
	}
	return (1);
}

int	valid_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '\n')
		return (free(str), 0);
	while (str[i] && str[i + 1])
	{
		if (!valid_char(str[i]) && str[i] != '\n')
			return (free(str), 0);
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (free(str), 0);
		i++;
	}
	return (1);
}

char	*read_file(char *file)
{
	int		fd;
	char	*line;
	char	*join;

	if (!check_file(file))
		return (NULL);
	join = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (perror("Error fd"), NULL);
	line = ft_line(fd);
	if (!line)
		return (free(line), perror("Error"), NULL);
	while (line != NULL)
	{
		join = ft_strjoin_gnl(join, line);
		free(line);
		line = ft_line(fd);
	}
	close(fd);
	return (join);
}

char	**read_map(char *file)
{
	char	*join;
	int		i;
	char	**mtx;

	i = 0;
	join = read_file(file);
	if (!join)
		return (NULL);
	if (!valid_string(join))
		return (perror("Error map"), NULL);
	mtx = split_into_mtx(join);
	return (mtx);
}
