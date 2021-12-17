/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemmanue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:35:34 by bemmanue          #+#    #+#             */
/*   Updated: 2021/05/30 15:24:04 by bemmanue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_input(int fd, char **line, char **buf)
{
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	*buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!*buf || read(fd, buf, 0))
	{
		free(*buf);
		return (-1);
	}
	return (0);
}

static int	check_remain(char **buf, char **remain, char **line)
{
	char	*n;
	char	*temp;

	if (*remain)
	{
		n = ft_strchr(*remain, '\n');
		if (n)
		{
			*n++ = '\0';
			*line = ft_strdup(*remain);
			temp = *remain;
			*remain = ft_strdup(n);
			free(temp);
			free(*buf);
			return (1);
		}
		*line = ft_strdup(*remain);
		free(*remain);
		*remain = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

static int	ft_buffer(char *buf, char **remain, char **line)
{
	char	*temp;

	if (remain)
	{
		*remain = ft_strchr(buf, '\n');
		*(*remain)++ = '\0';
		*remain = ft_strdup(*remain);
	}
	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
	if (remain)
		free(buf);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			endline;
	static char	*remain[4096];

	if (check_input(fd, line, &buf))
		return (-1);
	if (check_remain(&buf, &remain[fd], line))
		return (1);
	endline = read(fd, buf, BUFFER_SIZE);
	while (endline > 0)
	{
		buf[endline] = '\0';
		if (ft_strchr(buf, '\n'))
			return (ft_buffer(buf, &remain[fd], line));
		(void)ft_buffer(buf, NULL, line);
		endline = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (endline < 0)
		return (-1);
	return (0);
}
