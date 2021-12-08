#include <stdio.h>
#include "ft_printf.h"
int main()
{
	printf("%d   %d  \n", printf("%u\n", -1), ft_printf("%u\n", -1));
}
