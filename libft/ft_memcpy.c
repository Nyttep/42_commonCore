#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp1;
	const char	*tmp2;
	size_t		i;

	i = -1;
	tmp1 = dest;
	tmp2 = src;
	while (n > ++i)
		tmp1[i] = tmp2[i];
	return (dest);
}
