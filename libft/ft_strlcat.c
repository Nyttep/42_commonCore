#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t    lendest;    
    size_t    lensrc;
    size_t    i;

    i = 0;
    lendest = ft_strlen(dest);
    lensrc = ft_strlen(src);
    if (size == 0)
        return (lensrc);
    if (size <= lendest)
        return (size + lensrc);
    while (size && (--size - lendest) && src[i])
    {
        dest[lendest + i] = src[i];
        i++;
    }
    dest[lendest + i] = '\0';
    return (lensrc + lendest);
}
