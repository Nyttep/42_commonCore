#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
char	*get_next_line(int fd);
int	main(void)
{
	//int		fd;
	char	*str;

	//fd = open("./text.txt", O_RDONLY);
	str = get_next_line(1000);
	printf("%s", str);
	free(str);
}
