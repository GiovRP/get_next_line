/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giribeir <giovani.mack@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:32:26 by giribeir          #+#    #+#             */
/*   Updated: 2021/11/19 20:56:16 by giribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_read_to_writer(int fd, char *writer)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(writer, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		writer = ft_strjoin(writer, buff);
	}
	free(buff);
	return (writer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*writer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	writer = ft_read_to_writer(fd, writer);
	if (!writer)
		return (NULL);
	line = ft_get_line(writer);
	writer = ft_restart_writer(writer);
	return (line);
}
