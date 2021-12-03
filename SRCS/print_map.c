/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:18:12 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:34:19 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	create_map(t_window *win)
{
	t_check_map		var;

	var.x = 0;
	while (win->map[var.x])
	{
		var.y = 0;
		while (win->map[var.x][var.y])
		{
			if (win->map[var.x][var.y] == '0')
				mlx_put_image_to_window(win->mlx_ptr, win->mlx_ptr,
					win->floor.img, var.y * 50, var.x * 50);
			else if (win->map[var.x][var.y] == '1')
				mlx_put_image_to_window(win->mlx_ptr, win->mlx_ptr,
					win->walls.img, var.y * 50, var.x * 50);
			else if (win->map[var.x][var.y] == 'E')
				print_exit(win, var);
			else if (win->map[var.x][var.y] == 'C')
				print_collectible(win, var);
			else if (win->map[var.x][var.y] == 'P')
				print_player(win, var);
			var.y++;
		}
		var.x++;
	}
}
