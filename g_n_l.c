#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
char *get_next_line(int fd)
{
	int i = 0, j;
	char	*buf;

	if (!(buf = (char *)malloc(sizeof(char) * 4)))
		return (NULL);
	while ((j = read(fd, &buf[i], 1)) != 0 && buf[i] != '\n' && buf[i] != '\0');
		i++;
	buf[i] = '\0';
    if (!buf[0])
        return (NULL);
	return (buf);
}
