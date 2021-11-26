#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;
	size_t				i;
	int					res;

	i = 0;
	res = 0;
	tmp1 = s1;
	tmp2 = s2;
	while (i < n)
	{
		res = tmp1[i] - tmp2[i];
		i++;
	}
	return (res);
}
