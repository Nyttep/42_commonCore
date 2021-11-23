#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		while (big[i + j] == little[j] && big[i + j] && little[j])
		{
			if (little[j + 1] == 0)
				return ((char *) &big[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
