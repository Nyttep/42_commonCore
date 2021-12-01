#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	t_list	*current;

	first = malloc(sizeof(t_list));
	if (!first)
		return(NULL)
	first->content = f(lst->content);
	lst = lst->next;
	current = first;
	while (lst)
	{
		new = malloc(sizeof(t_list));
		if (!new)
		{
			ft_lstclear(first, del); //euuuuh c'est comme ça qu'on envoie un pointeur de fonctions ???
			return (NULL);
		}
		current->next = new;
		current = current->next;
		current->content = f(lst->content);
		lst = lst->next;
	}
	return (first);
}
