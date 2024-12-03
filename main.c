#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char	*hh;
	int		fd = open("hh.txt", O_RDONLY, 777);

	hh = get_next_line(fd);
	printf("%s", hh);
	free(hh);

	hh = get_next_line(fd);
	printf("%s", hh);
	free(hh);

	hh = get_next_line(fd);
	printf("%s", hh);
	free(hh);

	hh = get_next_line(fd);
	printf("%s", hh);
	free(hh);
	
}
