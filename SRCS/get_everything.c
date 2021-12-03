/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_everything.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:46:08 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:33:46 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	get_everything(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
