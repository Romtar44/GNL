#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	char	*new_line;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strnlen(line) + ft_strnlen(buffer);
	new_line = (char *)malloc(sizeof(char) * j + 1);
	if (!new_line)
		return (NULL);
	j = 0;
	while (line[i])
		new_line[j++] = line[i++];
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		new_line[j++] = buffer[i++];
	if (buffer[i] == '\n')
	{	
		new_line[j] = '\n';
		++j;
	}
	new_line[j] = 0;
	free(line);
	return (new_line);
}

char	*free_line(char *line)
{
	if (!line)
		return (NULL);
	free (line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	line = ft_strdup();
	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) == -1)
		return (free_line(line));
	line = ft_strjoin(line, buffer);
	if (n_ny_n(buffer))
		return (clean_buffer(buffer, line));
	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free_line(line));
		buffer[i] = 0;
		line = ft_strjoin(line, buffer);
		if (n_ny_n(buffer))
			return (clean_buffer(buffer, line));
	}
	if (i == 0)
		return (free_line(line));
	else
		return (clean_buffer(buffer, line));
}
