/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:26:57 by apita-da          #+#    #+#             */
/*   Updated: 2020/02/19 17:27:04 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(int fd, char **str, char **line, int rd)
{
	char	*tmp;
	char	*nl;

	if (!str[fd] && !rd)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((nl = ft_strchr(str[fd], '\n')))
	{
		*nl = '\0';
		*line = ft_strdup(str[fd]);
		tmp = ft_strdup(++nl);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	else
	{
		*line = str[fd];
		str[fd] = NULL;
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*str[4096];
	int			rd;
	char		*temp;

	if (!line || fd < 0 || fd > 4095 || (rd = read(fd, buff, 0)) == -1
			|| BUFFER_SIZE + 1 < 1)
		return (-1);
	while ((rd = read(fd, buff, BUFFER_SIZE + 1)) > 0)
	{
		buff[rd] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup("");
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (rd < 0)
		return (-1);
	rd = get_line(fd, str, line, rd);
	return (rd);
}
