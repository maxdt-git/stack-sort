/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:27:34 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/06 10:28:51 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_r(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ra(t_list **stack_a, t_bench *bench)
{
	do_r(stack_a);
	ft_printf("ra\n");
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_list **stack_b, t_bench *bench)
{
	do_r(stack_b);
	ft_printf("rb\n");
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	do_r(stack_a);
	do_r(stack_b);
	ft_printf("rr\n");
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
}
