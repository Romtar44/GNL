/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtournet <rtournet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 19:18:53 by rtournet          #+#    #+#             */
/*   Updated: 2021/08/30 19:20:51 by rtournet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*str;

	len = 0;
	while (s1[len])
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = 0;
	return (str);
}

int	n_ny_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

int	ft_strnlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	return (i);
}

char	*clean_buffer(char *buffer, char *line)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strnlen(buffer);
	if (buffer[j] == '\n')
		++j;
	while (buffer[i])
	{
		buffer[i] = buffer[j];
		++i;
		++j;
	}
	while (buffer[i])
	{
		buffer[i] = 0;
		++i;
	}
	return (line);
}
