#include "get_next_line.h"

char	*ft_strdup(void)
{
	char	*new_line;

	new_line = malloc(1);
	if (!new_line)
		return (NULL);
	*new_line = 0;
	return (new_line);
}

int	n_ny_n(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	ft_strnlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (str[i] == '\n')
		++i;
	return (i);
}

char	*clean_buffer(char *buffer, char *line)
{
	int	i;
	int	j;

	i = ft_strnlen(buffer);
	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		++i;
		++j;
	}
	while (buffer[j])
	{
		buffer[j] = 0;
		++j;
	}
	return (line);
}
