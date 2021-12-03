/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_PEC.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:03:24 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:34:26 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	print_player(t_window *win, t_check_map var)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->player.img, var.y * 50, var.x * 50);
	win->position.x = var.x * 50;
	win->position.y = var.y * 50;
}

void	print_exit(t_window *win, t_check_map var)
{
	if (get_everything(win->map))
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->exit.img, var.y * 50, var.x * 50);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->open.img, var.y * 50, var.x * 50);
	}
	else
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->floor.img, var.y * 50, var.x * 50);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
		win->close.img, var.y * 50, var.x * 50);
	}
}

void	print_collectibles(t_window *win, t_check_map var)
{
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->floor.img, var.y * 50, var.x * 50);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
	win->close.img, var.y * 50, var.x * 50);
}
