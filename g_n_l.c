#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
char	*get_next_line(int fd)
{
	int		i;
	int		j;
	char	*buf;
	char	c;

	i = 0;
	buf = (char *)malloc(sizeof(char) * 4);
	if (NULL == buf)
		return (NULL);
	j = read(fd, &c, 1);
	while (j != 0 && c != '\n' && c != '\0')
	{
		buf[i] = c;
		i++;
		j = read(fd, &c, 1);
	}
	buf[i] = '\0';
	if (!buf[0] || buf[0] == '\n')
	{
		free (buf);
		return (NULL);
	}
	return (buf);
}
