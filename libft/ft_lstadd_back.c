#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	ft_lstlast(*alst)->next = new;
	new->next = NULL;
	*alst = new;
}
