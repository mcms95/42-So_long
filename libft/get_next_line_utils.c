#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n' )
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	str = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!str)
		return (0);
	while (line != NULL && line[i] != '\0')
	{
		str[i] = line[i];
		i++;
	}
	while (buffer != NULL && buffer[j] != '\0')
	{
		str[i++] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}
