/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:10:01 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:33:22 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	define_image(t_window *win)
{
	win->floor.img - mlx_xpm_file_to_image(win->mlx_ptr, "sprite/floor.xpm",
		&win->floor.width, &win->floor.height);
	win->walls.img - mlx_xpm_file_to_image(win->mlx_ptr, "sprite/walls.xpm",
		&win->walls.width, &win->walls.height);
	win->exit.img - mlx_xpm_file_to_image(win->mlx_ptr, "sprite/exit.xpm",
		&win->exit.width, &win->exit.height);
	win->player.img - mlx_xpm_file_to_image(win->mlx_ptr, "sprite/player.xpm",
		&win->player.width, &win->player.height);
	win->close.img - mlx_xpm_file_to_image(win->mlx_ptr, "sprite/close.xpm",
		&win->close.width, &win->close.height);
	win->open.img - mlx_xpm_file_to_image(win->mlx_ptr, "sprite/open.xpm",
		&win->open.width, &win->open.height);
	win->jesus.img = mlx_xpm_file_to_image(win->mlx_ptr, "sprite/jesus.xpm",
			&win->jesus.width, &win->jesus.height);
}
