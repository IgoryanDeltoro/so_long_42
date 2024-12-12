/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igoryan <igoryan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:24:26 by ibondarc          #+#    #+#             */
/*   Updated: 2024/12/12 12:37:33 by igoryan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static char	*fill_buf_by_line(int fd, char *total_str, char *buffer);
static char	*extract_line(char *line_buffer);
static char	*allocate_buffer(size_t size);

char	*get_next_line(int fd)
{
	static char	*total_str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(total_str);
		total_str = NULL;
		return (NULL);
	}
	buffer = allocate_buffer(BUFFER_SIZE);
	line = fill_buf_by_line(fd, total_str, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	total_str = extract_line(line);
	return (line);
}

static char	*fill_buf_by_line(int fd, char *total_str, char *buffer)
{
	ssize_t	buf_read;
	char	*temp;

	buf_read = 1;
	while (buf_read > 0)
	{
		buf_read = read(fd, buffer, BUFFER_SIZE);
		if (buf_read == -1)
		{
			free(total_str);
			total_str = NULL;
			return (NULL);
		}
		if (buf_read == 0)
			break ;
		buffer[buf_read] = '\0';
		if (!total_str)
			total_str = ft_strdup("");
		temp = total_str;
		total_str = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (total_str);
}

static char	*extract_line(char *total_str)
{
	char	*line;
	int	i;
	int	j;

	i = 0;
	while (total_str[i] != '\n' && total_str[i] != '\0')
		i++;
	if (total_str[i] == '\0')
		return (NULL);
	j = 0;
	line = allocate_buffer(ft_strlen(total_str) - i);
	if (!line)
		return (NULL);
	while (j < (ft_strlen(total_str) - i))
	{
		line[j] = total_str[i + j + 1];
		j++;
	}
	if (*line == 0)
	{
		free(line);
		line = NULL;
	}
	total_str[i] = '\0';
	return (line);
}

static char	*allocate_buffer(size_t size)
{
	char	*buffer;
	
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	return (buffer);
}
