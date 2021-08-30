/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <rtournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:18:40 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/30 19:19:28 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	j = ft_strnlen(line) + ft_strnlen(buffer);
	new_line = (char *)malloc(sizeof(char) * j + 2);
	if (!new_line)
		return (NULL);
	j = 0;
	while (line[i])
		new_line[j++] = line[i++];
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		new_line[j++] = buffer[i++];
	if (buffer[i] == '\n')
		new_line[j++] = '\n';
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

char	*free_line(char *line)
{
	if (!line)
		return (NULL);
	free (line);
	line = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (NULL);
	line = ft_strdup("");
	line = ft_strjoin(line, buffer);
	i = 1;
	while (i > 0 && !n_ny_n(buffer))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free_line(line));
		else if (i)
		{
			buffer[i] = '\0';
			line = ft_strjoin(line, buffer);
		}
		else if (i == 0 && buffer[0] != 0)
			return (clean_buffer(buffer, line));
		else
			return (free_line(line));
	}
	return (clean_buffer(buffer, line));
}
