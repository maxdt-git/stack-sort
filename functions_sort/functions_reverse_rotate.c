/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:27:25 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/06 10:27:28 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_r(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	before_last = NULL;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	ft_lstadd_front(stack, last);
}

void	rra(t_list **stack_a, t_bench *bench)
{
	do_rev_r(stack_a);
	ft_printf("rra\n");
	if (bench)
	{
		bench->rra++;
		bench->total++;
	}
}

void	rrb(t_list **stack_b, t_bench *bench)
{
	do_rev_r(stack_b);
	ft_printf("rrb\n");
	if (bench)
	{
		bench->rrb++;
		bench->total++;
	}
}

void	rrr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	do_rev_r(stack_a);
	do_rev_r(stack_b);
	ft_printf("rrr\n");
	if (bench)
	{
		bench->rrr++;
		bench->total++;
	}
}
