#include <stdio.h>

typedef struct elem elem;
struct elem
{
	int 	nb;
	elem	*next;
};

int	main(void)
{
	elem	*elem1;
	elem	*elem2;
	elem	*i;

	elem1 = malloc(sizeof(elem1));
	elem2 = malloc(sizeof(elem2));
	i = elem1;
	elem1->nb = 3;
	elem1->next = elem2;
	elem2->nb = 5;
	elem2->next = NULL;
	while (i)
	{
		printf("%d", i->nb);
		i = i->next;
	}
		i->next = 
}
