/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:29:00 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/06 10:29:03 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_s(t_list **stack)
{
	t_list	*sa1;
	t_list	*sa2;
	void	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	sa1 = *stack;
	sa2 = (*stack)->next;
	tmp = sa1->content;
	sa1->content = sa2->content;
	sa2->content = tmp;
}

void	sa(t_list **stack_a, t_bench *bench)
{
	do_s(stack_a);
	ft_printf("sa\n");
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
}

void	sb(t_list **stack_b, t_bench *bench)
{
	do_s(stack_b);
	ft_printf("sb\n");
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	do_s(stack_a);
	do_s(stack_b);
	ft_printf("ss\n");
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
}
