/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:37:19 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/21 17:02:32 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"
#include "../libs/mlx_keycode.h"

static int	make_width(char *file)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	i = ft_strlen(line);
	free_memory_line(line);
	close (fd);
	return (i);
}

static int	make_height(char *file)
{
	int		fd;
	int		nb_line;
	char	*line;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		++nb_line;
		free (line);
	}
	++nb_line;
	free_memory_line(line);
	close (fd);
	return (nb_line);
}

int	deal_key(int key, t_window *win)
{
	if (key == KEY_ECHAP)
	{
		printf("\e[0;33m[Esc]");
		printf("\e[0;35mGame closes.\n");
		exit (0);
	}
}

int	escape(t_window *win)
{
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	printf("\e[0;35mGame closes.\n");
	exit (0);
}

int	main(int argc, char **argv)
{
	t_window	win;

	if (argc != 2)
	{
		printf("\e[0;35mError found. Do you mean ./so_long maps/basic.ber ?\n");
		return (0);
	}
	win.mlx_ptr = mlx_init();
	define_image(&win);
	if (checking_function(&win, argv[1]))
	{
		win.map_img.height = make_height(argv[1]) * 50;
		win.map_img.width = make_width(argv[1]) * 50;
		win.win_ptr = mlx_new_window(win.mlx_ptr, \
			win.map_img.width, win.map_img.height, "so_long");
		create_map(&win);
		mlx_hook(win.win_ptr, 2, 0, deal_key, &win);
		mlx_hook(win.win_ptr, 17, 0, escape, &win);
		mlx_loop(win.mlx_ptr);
	}
	return (0);
}
