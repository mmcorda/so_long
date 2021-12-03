/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:48:44 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:33:10 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	check_solong_extension(char *file, char const *ext)
{
	int	file_size;
	int	ext_size;

	file_size = ft_strlen(file);
	ext_size = ft_strlen(ext);
	if (file_size < ext_size)
		return (0);
	while (ext_size >= 0)
	{
		if (ext[ext_size] != file[file_size])
			return (0);
		ext_size--;
		file_size--;
	}
	return (1);
}

int	checking_function(t_window *win, char *file)
{
	int		index;
	int		fd;
	int		line_count;

	index = 0;
	fd = open(file, O_RDONLY);
	if (!check_solong_extension(file, ".ber") || fd == -1)
	{
		ft_putstr_fd("Error.\nWrong extension.\n", 2);
		exit (1);
	}
	line_count = line_counter(fd);
	close(fd);
	if (line_count < 3)
	{
		ft_putstr_fd("Error.\nMap size is not correct.\n", 2);
		exit (1);
	}
	if (!print_next_line(win, file, line_count)
		|| !check_the_damn_walls(win->map, line_count - 1))
	{
		ft_putstr_fd("Error.\nMap setup is incorrect.\n", 2);
		exit (1);
	}
	return (1);
}

static int	line_counter(int fd)
{
	char	*line;
	int		nl;

	nl = 0;
	while (get_next_line(fd, &line) > 0)
	{
		++nl;
		free_memory_line(line);
	}
	++nl;
	free_memory_line(line);
	printf("%d\n", nl);
}

static int	print_next_line(t_window *win, char *file, int nl)
{
	int		index;
	int		fd;
	char	*line;
	int		line_size;

	index = 0;
	fd = open(file, O_RDONLY);
	win->map = calloc(sizeof(char *), nl + 1);
	line_size = -1;
	while (get_next_line(fd, &line) > 0)
	{
		win->map[index] = ft_strdup(line);
		if (line_size == -1)
			line_size = (int)ft_strlen(win->map[index]);
		free_memory_line(line);
		if ((int)strlen(win->map[index]) != line_size)
			return (0);
		++index;
	}
	win->map[++index] = ft_strdup(line);
	free_memory_line(line);
	close (fd);
	return (1);
}

static int	check_the_damn_walls(char **map, int line)
{
	t_check_map		var;

	var = (t_check_map){0};
	var.y = -1;
	while (map[++var.y])
	{
		var.x = -1;
		while (map[var.y][++var.x])
		{
			if (map[0][var.x] != '1' || map[line][var.x] != '1' || (map[var.y]
				[0] != '1' || map[var.y][ft_strlen(map[var.y]) - 1] != '1'))
				return (0);
			else if (map[var.y][var.x] == 'E')
				++var.exit;
			else if (map[var.y][var.x] == 'C')
				++var.collectible;
			else if (map[var.y][var.x] == 'P')
				++var.player;
			else if (map[var.y][var.x] != '0' && map[var.y][var.x] != '1')
				return (0);
		}
	}
	if (var.player != 1 || var.collectible < 1 || var.exit < 1)
		return (0);
	return (1);
}
