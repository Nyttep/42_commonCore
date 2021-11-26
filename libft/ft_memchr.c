#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmps;
	unsigned char		tmpc;
	size_t				i;

	tmps = s;
	tmpc = c;
	i = 0;
	while (i < n)
	{
		if (tmps[i] == tmpc)
			return (tmps + i);
		i++;
	}
	return (NULL);
}
