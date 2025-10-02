/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamarn <jalamarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:41:07 by jalamarn          #+#    #+#             */
/*   Updated: 2025/10/02 16:53:17 by jalamarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

char	*read_from_file(char *basin_buffer, int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			free(basin_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (ft_strchr(basin_buffer, '\n'))
			break ;
		if (bytes_read == 0)
			break ;
	}
	free(cup_buffer);
	return (basin_buffer);
}

char	*extract_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	return (line);
}

char	*obtain_remaining(char *buffer)
{
	int		i;
	int		j;
	char	*remaining;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	remaining = ft_calloc(ft_strlen(buffer + i) + 1, sizeof(char));
	if (!remaining)
		return (NULL);
	while (buffer[i])
		remaining[j++] = buffer[i++];
	free(buffer);
	return (remaining);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!basin_buffer[fd])
		basin_buffer[fd] = ft_calloc(1, sizeof(char));
	if (!ft_strchr(basin_buffer[fd], '\n'))
		basin_buffer[fd] = read_from_file(basin_buffer[fd], fd);
	if (!basin_buffer[fd])
	{
		free(basin_buffer[fd]);
		return (NULL);
	}
	line = extract_line(basin_buffer[fd]);
	basin_buffer[fd] = obtain_remaining(basin_buffer[fd]);
	return (line);
}
