/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:22:40 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/13 17:37:43 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_tmp_rank(t_list *stack_a, long *new_tab, long size)
{
	t_list		*tmp;
	long		rank;

	tmp = stack_a;
	while (tmp)
	{
		rank = 0;
		while (rank < size)
		{
			if (new_tab[rank] == (long)tmp->content)
			{
				tmp->content = (void *)rank;
				break ;
			}
			rank++;
		}
		tmp = tmp->next;
	}
	free (new_tab);
}

void	change_value_rank(t_list **stack_a)
{
	t_list		*tmp;
	long		index;
	long		size;
	long		*new_tab;

	tmp = *stack_a;
	size = ft_lstsize(*stack_a);
	new_tab = malloc(sizeof(long) * size);
	if (!new_tab)
		return ;
	index = 0;
	while (tmp)
	{
		new_tab[index] = (long)tmp->content;
		index++;
		tmp = tmp->next;
	}
	ft_sort_long_tab(new_tab, size);
	fill_tmp_rank(*stack_a, new_tab, size);
}

int	get_bit_count(long size)
{
	int		bits;
	long	max;

	bits = 0;
	max = 1;
	while (max < size)
	{
		max = max * 2;
		bits++;
	}
	return (bits);
}

void	radix_pass(t_list **stack_a, t_list **stack_b, t_bench *bench, long div)
{
	long	i;
	long	size;

	size = ft_lstsize(*stack_a);
	i = 0;
	while (i < size)
	{
		if (((long)(*stack_a)->content / div) % 2)
			ra(stack_a, bench);
		else
			pb(stack_a, stack_b, bench);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}

void	complex_algo_radix(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	long	size;
	long	bit;
	long	divisor;
	long	bits;

	if (good_order(*stack_a))
		return ;
	change_value_rank(stack_a);
	size = ft_lstsize(*stack_a);
	bit = 0;
	divisor = 1;
	bits = get_bit_count(size);
	while (bit < bits)
	{
		radix_pass(stack_a, stack_b, bench, divisor);
		divisor *= 2;
		bit++;
	}
}
