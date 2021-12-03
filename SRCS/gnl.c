/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorda <mcorda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:41:39 by mcorda            #+#    #+#             */
/*   Updated: 2021/10/12 17:34:03 by mcorda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"
#include "../libs/mlx_keycode.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static	int	is_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_free_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1len;
	int		s2len;

	s1len = 0;
	s2len = 0;
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 == NULL || s2 == NULL || !(new))
		return (NULL);
	while (s1[s1len] != '\0')
	{
		new[s1len] = s1[s1len];
		s1len++;
	}
	free(s1);
	while (s2[s2len] != '\0')
	{
		new[s1len] = s2[s2len];
		s1len++;
		s2len++;
	}
	new[s1len] = '\0';
	return (new);
}

static int	cut_the_line(int index, char *rest, char **line)
{
	int	len;

	*line = ft_substr(rest, 0, index);
	index++;
	len = ft_strlen(rest + index) + 1;
	rest = ft_memove(rest, rest + index, len);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest = NULL;
	char		bf[BUFFER_SIZE + 1];
	int			lu;
	int			index;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, bf, 0) < 0)
		return (-1);
	lu = 1;
	if (rest && is_char(rest, '\n') != -1)
	{
		index = is_char(rest, '\n');
		return (cut_the_line(index, rest, line));
	}
	while (lu > 0)
	{
		lu = read(fd, bf, BUFFER_SIZE);
		bf[lu] = '\0';
		rest = ft_free_strjoin(rest, bf);
		index = is_char(rest, '\n');
		if (index != -1)
			return (cut_the_line(index, rest, line));
	}
	ft_clean(&rest, line);
	return (0);
}
