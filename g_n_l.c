#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
char *get_next_line(int fd)
{
	int i = 0, j;
	char	*buf;
	char	c;

	if (!(buf = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	while ((j = read(fd, &c, 1)) != 0 && c != '\n' && c != '\0')
	{
		buf[i] = c;
		i++;
	}
	buf[i] = '\0';
    if (!buf[0] || buf[0] == '\n')
	{
		free (buf);
        return (NULL);
	}
	return (buf);
}
