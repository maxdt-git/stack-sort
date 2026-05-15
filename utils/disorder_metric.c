/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:51:37 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/05 16:47:36 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_list *stack)
{
	t_list	*i;
	t_list	*j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			total_pairs++;
			if ((long)i->content > (long)j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / (float)total_pairs);
}
