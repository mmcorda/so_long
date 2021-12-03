/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:23:40 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:33:27 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	free_memory_line(char *line)
{
	if (!line)
	{
		exit(EXIT_FAILURE);
	}
	free(line);
	line = NULL;
}
