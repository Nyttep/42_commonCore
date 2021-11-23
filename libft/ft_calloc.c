#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;
	size_t		i;

	i = 0;
	if ((nmemb * size) < -2147483648 || (nmemb * size) > 2147483647)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (NULL);
	ret = malloc(nmemb);
	while (ret[i] != NULL)
	{
		ret[i] = malloc(size);
		i++;
	}
	ft_bzero(ret, nmemb);
	return (ret);
}
