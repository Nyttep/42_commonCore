#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	int		*tmp;

	tmp = s;
	i = 0;
	while (n > i)
		tmp[i++] = c;
	return (s);
}
