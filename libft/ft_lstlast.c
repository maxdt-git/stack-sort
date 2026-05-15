/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:38:09 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/23 20:45:10 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->content = content;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!*lst)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = ft_lstlast(*lst);
// 	last->next = new;
// }

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("A");
// 	ft_lstadd_back(&lst, ft_lstnew("B"));
// 	ft_lstadd_back(&lst, ft_lstnew("C"));
// 	printf("last: %s\n", (char *)ft_lstlast(lst)->content);
// }
