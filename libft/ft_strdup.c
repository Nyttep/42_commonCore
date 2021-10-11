#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	int		i;

	i = -1;
	len = ft_strlen(s);
	ret = (char *) malloc(sizeof(char) * (len + 1));
	ret[len] = 0;
	while (s[++i])
		ret[i] = s[i];
	return (ret);
}
