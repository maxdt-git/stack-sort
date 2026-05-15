/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:02:12 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/05 14:02:13 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_printf("pa\n");
	if (bench)
	{
		bench->pa++;
		bench->total++;
	}
}

void	pb(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	t_list	*tmp;

	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_printf("pb\n");
	if (bench)
	{
		bench->pb++;
		bench->total++;
	}
}
