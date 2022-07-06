/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giribeir <giovani.mack@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:41:23 by giribeir          #+#    #+#             */
/*   Updated: 2021/11/15 20:40:18 by giribeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_to_writer(int fd, char *writer);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *writer, char *buff);
size_t	ft_strlen(char *s);
char	*ft_get_line(char *writer);
char	*ft_restart_writer(char *writer);

#endif
