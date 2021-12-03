/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_is_over.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 19:01:47 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:33:34 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	game_is_over(t_window *win)
{
	mlx_put_image_to_window(win->mlx_ptr, win->mlx_ptr, win->jesus.img, 0, 0);
	ft_putstr_fd("Congrats! You won!\n", 2);
	exit (0);
	mlx_destroy_window(win->mlx_ptr, win->mlx_ptr);
}
