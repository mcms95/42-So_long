#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_string_join(char *line, char *buf);
int		buffer(char *buf);
void	clearbuffer(char *buf);

#endif