/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:07:03 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:34:11 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	g_global = 1;

void	all_moves(int key, t_window *win)
{
	down_move(key, win);
	upper_move(key, win);
	left_move(key, win);
	right_move(key, win);
}

void	down_move(int key, t_window *win)
{
	if (key == 1 && win->map[(win->position.x / 50) + 1]
		[win->position.y / 50] != '1' && win->map[(win->position.x / 50) + 1]
		[win->position.y / 50] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->mlx_ptr, win->floor.img, \
				win->position.y, win->position.x);
		win->map[(win->position.x / 50) + 1][win->position.y / 50] = '0';
		{
			win->position.x += 50;
			printf("%d\n", g_global++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr,
			win->player.img, win->position.y, win->position.x);
	}
	else if (key == 1 && win->map[(win->position.x / 50) + 1]
		[(win->position.y / 50) + 1] == 'E' && get_everything(win->map))
	{
		win->position.x += 50;
		game_is_over(win);
	}
}

void	right_move(int key, t_window *win)
{
	if (key == 2 && win->map[win->position.x / 50]
		[(win->position.y / 50) + 1] != '1' \
		&& win->map[win->position.x / 50][(win->position.y / 50) + 1] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->floor.img, win->position.y, win->position.x);
		win->map[win->position.x / 50][(win->position.y / 50) + 1] = '0';
		{
			win->position.y += 50;
			printf("%d\n", g_global++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->player.img, win->position.y, win->position.x);
	}
	else if (key == 2 && get_everything(win->map)
		&& win->map[win->position.x / 50][(win->position.y / 50) + 1] == 'E')
	{
		win->position.y += 50;
		game_is_over(win);
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->jesus.img, win->position.y, win->position.x);
	}
}

void	left_move(int key, t_window *win)
{
	if (key == 0 && win->map[win->position.x / 50]
		[(win->position.y / 50) - 1] != '1' \
		&& win->map[win->position.x / 50][(win->position.y / 50) - 1] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->floor.img, win->position.y, win->position.x);
		win->map[win->position.x / 50][(win->position.y / 50) - 1] = '0';
		{
			win->position.y -= 50;
			printf("%d\n", g_global++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->player.img, win->position.y, win->position.x);
	}
	else if (key == 0 && win->map[(win->position.x / 50)] \
		[(win->position.y / 50) - 1] == 'E' && get_everything(win->map))
	{
		win->position.y -= 50;
		game_is_over(win);
	}
}

void	upper_move(int key, t_window *win)
{
	if (key == 13 && win->map[(win->position.x / 50) - 1]
		[win->position.y / 50] != '1' \
		&& win->map[(win->position.x / 50) - 1][win->position.y / 50] != 'E')
	{
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->floor.img, \
			win->position.y, win->position.x);
		win->map[(win->position.x / 50) - 1][win->position.y / 50] = '0';
		{
			win->position.x -= 50;
			printf("%d\n", g_global++);
		}
		mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, \
			win->player.img, win->position.y, win->position.x);
	}
	else if (key == 13 && win->map[(win->position.x / 50) - 1] \
		[win->position.y / 50] == 'E' && get_everything(win->map))
	{
		win->position.y -= 50;
		game_is_over(win);
	}
}
