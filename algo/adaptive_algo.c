/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:27:56 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/07 18:36:23 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	low_algo(t_list **stack_a, t_bench *bench)
{
	int	sorted;
	int	size;
	int	i;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (!good_order(*stack_a) && i < size * size)
	{
		sorted = 1;
		if ((long)(*stack_a)->content > (long)(*stack_a)->next->content)
		{
			sa(stack_a, bench);
			sorted = 0;
		}
		if (!sorted || !good_order(*stack_a))
			ra(stack_a, bench);
		i++;
	}
}

void	adaptive_algo(t_list **stack_a, t_list **stack_b, t_bench *bench,
		t_flags *flags)
{
	float	disorder;

	disorder = compute_disorder(*stack_a);
	if (disorder < 0.2)
	{
		flags->algo = "Adaptive / O(n)";
		low_algo(stack_a, bench);
	}
	else if (disorder < 0.5)
	{
		flags->algo = "Adaptive / O(n√n)";
		medium_algo(stack_a, stack_b, bench);
	}
	else
	{
		flags->algo = "Adaptive / O(nlogn)";
		complex_algo_radix(stack_a, stack_b, bench);
	}
}
