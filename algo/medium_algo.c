/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:25:34 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/08 11:46:09 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_min_chunk(t_list *stack, int chunk)
{
	t_list	*i;
	t_list	*j;
	int		count;

	i = stack;
	while (i != NULL)
	{
		j = stack;
		count = 0;
		while (j != NULL)
		{
			if ((long)j->content < (long)i->content)
				count++;
			j = j->next;
		}
		if (count == chunk - 1)
			return ((long)i->content);
		i = i->next;
	}
	return (0);
}

long	find_max_pos(t_list *stack)
{
	long	max;
	long	pos;
	long	i;

	max = (long)stack->content;
	pos = 0;
	i = 0;
	while (stack != NULL)
	{
		if ((long)stack->content > max)
		{
			max = (long)stack->content;
			pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (pos);
}

void	rotate_max(t_list **stack, t_bench *bench)
{
	long	max_pos;
	long	i;

	max_pos = find_max_pos(*stack);
	i = 0;
	if (max_pos > ft_lstsize(*stack) / 2)
	{
		while (i < ft_lstsize(*stack) - max_pos)
		{
			rrb(stack, bench);
			i++;
		}
	}
	else
	{
		while (i < max_pos)
		{
			rb(stack, bench);
			i++;
		}
	}
}

void	push_chunk(t_list **stack_a, t_list **stack_b, t_bench *bench,
		int chunk)
{
	long	n;
	int		pushed;

	if (ft_lstsize(*stack_a) <= chunk)
	{
		while (*stack_a != NULL)
			pb(stack_a, stack_b, bench);
	}
	n = find_min_chunk(*stack_a, chunk);
	pushed = 0;
	while (pushed < chunk && *stack_a != NULL )
	{
		if ((long)(*stack_a)->content <= n)
		{
			pb(stack_a, stack_b, bench);
			pushed++;
		}
		else
			ra(stack_a, bench);
	}
}

void	medium_algo(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	int	chunk;
	int	i;

	i = 1;
	while (i * i <= ft_lstsize(*stack_a))
		i++;
	chunk = i - 1;
	while (*stack_a != NULL)
		push_chunk(stack_a, stack_b, bench, chunk);
	while (*stack_b != NULL)
	{
		rotate_max(stack_b, bench);
		pa(stack_a, stack_b, bench);
	}
}
