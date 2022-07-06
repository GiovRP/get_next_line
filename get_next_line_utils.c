/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giribeir <giovani.mack@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:41:13 by giribeir          #+#    #+#             */
/*   Updated: 2021/11/15 20:44:41 by giribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *writer, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!writer)
	{
		writer = (char *)malloc(1 * sizeof(char));
		writer[0] = '\0';
	}
	if (!writer || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(writer) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (writer)
		while (writer[++i] != '\0')
			str[i] = writer[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(writer) + ft_strlen(buff)] = '\0';
	free(writer);
	return (str);
}

char	*ft_get_line(char *writer)
{
	int		i;
	char	*str;

	i = 0;
	if (!writer[i])
		return (NULL);
	while (writer[i] && writer[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (writer[i] && writer[i] != '\n')
	{
		str[i] = writer[i];
		i++;
	}
	if (writer[i] == '\n')
	{
		str[i] = writer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_restart_writer(char *writer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (writer[i] && writer[i] != '\n')
		i++;
	if (!writer[i])
	{
		free(writer);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(writer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (writer[i])
		str[j++] = writer[i++];
	str[j] = '\0';
	free(writer);
	return (str);
}
