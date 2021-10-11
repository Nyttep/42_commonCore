#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int					len;
	char				*ret;
	unsigned int		i;

	i = 0;
	len = ft_strlen(s);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	ret[len] = 0;
	while (i < len)
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
