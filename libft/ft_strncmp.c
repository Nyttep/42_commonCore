#include "libft.h"

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	int	res;
	size_t	i;
	int	all1;
	int	all2;

	all1 = 0;
	all2 = 0;
	i = 0;
	res = 0;
	while (all1 == all2 && (s1[i] || s2[i]) && n > 0)
	{
		all1 = all1 + s1[i];
		all2 = all2 + s2[i];
		i++;
		n--;
	}
	res = all1 - all2;
	return (res);
}
