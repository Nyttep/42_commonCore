#include <stdio.h>
#include <string.h>
int	ft_strncmp(const char	*s1, const char	*s2, size_t	n);
int main(void)
{
	printf("%d\n", ft_strncmp("abcde", "qwert", (size_t)5));
	printf("%d\n", strncmp("abcde", "qwert", (size_t)5));
}
