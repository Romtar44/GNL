#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buffer);
char	*clean_buffer(char *buffer, char *line);
int		n_ny_n(char *str);
int		ft_strnlen(char *str);
char	*ft_strdup(char *str);

#endif