/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:40:20 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/23 20:53:16 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	while (*lst)
	{
		node = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = node;
	}
}

// char	*ft_strdup(const char *s)
// {
// 	char	*dup;
// 	size_t	i;
// 	size_t	slen;

// 	slen = 0;
// 	while (s[slen])
// 		slen++;
// 	dup = malloc(sizeof(char) * (slen + 1));
// 	if (!dup)
// 		return (NULL);
// 	i = 0;
// 	while (i < slen)
// 	{
// 		dup[i] = s[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
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

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew(ft_strdup("A"));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("B")));
// 	ft_lstclear(&lst, free);
// 	printf("lst: %p (expected NULL)\n", lst);
// }
