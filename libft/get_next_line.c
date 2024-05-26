#include "get_next_line.h"

int	buffer(char *buf)
{
	int			i;
	int			trig;
	int			j;

	trig = 0;
	i = 0;
	j = 0;
	while (buf[i] != '\0')
	{
		if (trig == 1)
		{
			buf[j] = buf[i];
			j++;
		}
		if (buf[i] == '\n')
			trig = 1;
		buf[i] = 0;
		i++;
	}
	return (trig);
}

void	clearbuffer(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		buf[i] = 0;
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			trig;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		clearbuffer(buf);
		return (NULL);
	}
	line = NULL;
	trig = 0;
	while (trig == 0 && (buf[0] != 0 || read(fd, buf, BUFFER_SIZE) != 0))
	{
		line = ft_string_join(line, buf);
		trig = buffer(buf);
	}
	return (line);
}
