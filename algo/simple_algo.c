/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:29:43 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/06 11:20:49 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_algo(t_list **stack_a, t_list **stack_b, t_bench *bench)
{
	while (*stack_a)
	{
		rotate_min(stack_a, bench);
		pb(stack_a, stack_b, bench);
	}
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}
