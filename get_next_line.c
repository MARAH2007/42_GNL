/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazzal <mnazzal@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:29:36 by mnazzal           #+#    #+#             */
/*   Updated: 2026/10/14 14:09:00 by mnazzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fill_saved(int fd, char **saved, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && (!*saved || !ft_strchr(*saved, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(*saved);
			*saved = NULL;
			return (0);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0 && !append_buffer(saved, buffer))
			return (0);
	}
	return (1);
}

static int	read_and_save(int fd, char **saved)
{
	char	*buffer;

	if (*saved && ft_strchr(*saved, '\n'))
		return (1);
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(*saved);
		*saved = NULL;
		return (0);
	}
	if (!fill_saved(fd, saved, buffer))
	{
		free(buffer);
		return (0);
	}
	free(buffer);
	return (1);
}

static char	*extract_line(char *saved)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (saved[i] != '\0' && saved[i] != '\n')
		i++;
	if (saved[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = saved[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*update_saved(char *saved)
{
	size_t	i;
	size_t	j;
	char	*new_saved;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	if (saved[i] == '\0' || saved[i + 1] == '\0')
	{
		free(saved);
		return (NULL);
	}
	i++;
	new_saved = malloc(ft_strlen(saved + i) + 1);
	if (!new_saved)
	{
		free(saved);
		return (NULL);
	}
	j = 0;
	while (saved[i])
		new_saved[j++] = saved[i++];
	new_saved[j] = '\0';
	free(saved);
	return (new_saved);
}

char	*get_next_line(int fd)
{
	static char	*saalbaqe;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_save(fd, &saalbaqe))
		return (NULL);
	if (!saalbaqe || saalbaqe[0] == '\0')
	{
		free(saalbaqe);
		saalbaqe = NULL;
		return (NULL);
	}
	line = extract_line(saalbaqe);
	if (!line)
		return (NULL);
	saalbaqe = update_saved(saalbaqe);
	return (line);
}
