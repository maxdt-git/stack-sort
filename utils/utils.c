/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:08:56 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/08 16:20:28 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_order(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if ((long)stack_a->content > (long)stack_a->next->content)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	is_sign(char c)
{
	if (c == '+' || c == '-' )
		return (1);
	return (0);
}

int	is_number(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	if (str[0] == '\0')
		return (0);
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		n = n * 10 + (str[i] - '0');
		if (str[0] == '-' && - n < -2147483648)
			return (0);
		if (str[0] != '-' && n > 2147483647)
			return (0);
		i++;
	}
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

void	ft_sort_long_tab(long *tab, long size)
{
	long		a;
	long		b;
	long		temp;

	a = 0;
	while (a < size)
	{
		b = 0;
		while (b < size - 1)
		{
			if (tab[b] > tab[b + 1])
			{
				temp = tab[b];
				tab[b] = tab[b + 1];
				tab[b + 1] = temp;
			}
			b++;
		}
		a++;
	}
}
