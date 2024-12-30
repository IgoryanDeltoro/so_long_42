/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibondarc <ibondarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:24:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/27 12:54:47 by ibondarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int		fill_buf_by_line(int fd, char **line);
char	*allocate_buffer(size_t size);

int	get_next_line(int fd, char **line)
{
	int	res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	res = fill_buf_by_line(fd, line);
	return (res);
}

int	fill_buf_by_line(int fd, char **line)
{
	ssize_t	buf_read;
	char	*temp;
	char	*buffer;

	buf_read = 1;
	buffer = allocate_buffer(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (buf_read > 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read == -1)
			return (free(buffer), -1);
		if (buf_read == 0)
			break ;
		buffer[buf_read] = '\0';
		if (!(*line))
			*line = ft_strdup("");
		temp = *line;
		*line = ft_strjoin(temp, buffer);
		free(temp);
		if (!(*line))
			return (free(buffer), -1);
	}
	return (free(buffer), 0);
}

char	*allocate_buffer(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc((size) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}
