/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:26:43 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/23 20:46:12 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
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
// 	printf("size: %d\n", ft_lstsize(lst));
// }
