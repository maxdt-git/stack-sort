/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:03:58 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/07 19:01:38 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dupplicate(t_list *stack)
{
	t_list	*i;
	t_list	*j;

	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if ((long)i->content == (long)j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_bench	bench;
	t_flags	flags;

	stack_b = NULL;
	if (ac < 2)
		return (0);
	init_bench(&bench);
	flags = parse_flags(av);
	stack_a = build_stack(ac, av, flags.flag_start);
	if (!stack_a)
		return (1);
	flags.disorder = compute_disorder(stack_a);
	run_algo(&stack_a, &stack_b, &bench, &flags);
	if (flags.bench_mode)
		print_bench(&bench, flags.disorder, flags.algo);
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
	return (0);
}
