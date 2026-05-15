/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:14:31 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/13 12:12:34 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack, t_bench *bench)
{
	if ((long)(*stack)->content > (long)(*stack)->next->content)
		sa(stack, bench);
}

void	sort_three(t_list **stack, t_bench *bench)
{
	long	first;
	long	second;
	long	third;

	first = (long)(*stack)->content;
	second = (long)(*stack)->next->content;
	third = (long)(*stack)->next->next->content;
	if (first < second && second > third && third > first)
	{
		sa(stack, bench);
		ra(stack, bench);
	}
	if (first > second && second < third && third > first)
		sa(stack, bench);
	if (first < second && second > third && third < first)
		rra(stack, bench);
	if (first > second && second < third && third < first)
		ra(stack, bench);
	if (first > second && second > third)
	{
		sa(stack, bench);
		rra(stack, bench);
	}
}

long	find_min_pos(t_list *stack)
{
	long	min;
	long	pos;
	long	i;

	min = (long)stack->content;
	pos = 0;
	i = 0;
	while (stack != NULL)
	{
		if ((long)stack->content < min)
		{
			min = (long)stack->content;
			pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (pos);
}

void	rotate_min(t_list **stack, t_bench *bench)
{
	long	min_pos;
	long	i;

	min_pos = find_min_pos(*stack);
	i = 0;
	if (min_pos > ft_lstsize(*stack) / 2)
	{
		while (i < ft_lstsize(*stack) - min_pos)
		{
			rra(stack, bench);
			i++;
		}
	}
	else
	{
		while (i < min_pos)
		{
			ra(stack, bench);
			i++;
		}
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	rotate_min(stack_a, bench);
	pb(stack_a, stack_b, bench);
	rotate_min(stack_a, bench);
	pb(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	pa(stack_a, stack_b, bench);
	pa(stack_a, stack_b, bench);
}
