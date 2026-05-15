/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:15:21 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/14 10:08:15 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*build_stack(int ac, char **av, int start)
{
	t_list	*stack;
	int		i;

	stack = NULL;
	i = start;
	while (i < ac)
	{
		if (!is_number(av[i]))
		{
			write(2, "Error\n", 6);
			ft_lstclear(&stack, NULL);
			return (NULL);
		}
		ft_lstadd_back(&stack, ft_lstnew((void *)(long)ft_atoi(av[i])));
		i++;
	}
	if (dupplicate(stack))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (stack);
}

t_flags	parse_flags(char **av)
{
	t_flags	flags;

	flags.bench_mode = 0;
	flags.flag_start = 1;
	flags.algo = NULL;
	if (ft_strncmp(av[1], "--bench", 7) == 0)
	{
		flags.bench_mode = 1;
		flags.flag_start = 2;
		flags.algo = av[2];
		if (av[2] && (ft_strncmp(av[2], "--simple", 8) == 0
				|| ft_strncmp(av[2], "--medium", 8) == 0
				|| ft_strncmp(av[2], "--complex", 9) == 0
				|| ft_strncmp(av[2], "--adaptive", 10) == 0))
			flags.flag_start = 3;
	}
	else if (ft_strncmp(av[1], "--simple", 8) == 0
		|| ft_strncmp(av[1], "--medium", 8) == 0
		|| ft_strncmp(av[1], "--complex", 9) == 0
		|| ft_strncmp(av[1], "--adaptive", 10) == 0)
	{
		flags.flag_start = 2;
		flags.algo = av[1];
	}
	return (flags);
}

void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
}

static int	handle_small(t_list **a, t_bench *bench)
{
	if (good_order(*a))
		return (1);
	if (ft_lstsize(*a) == 2)
	{
		sort_two(a, bench);
		return (1);
	}
	if (ft_lstsize(*a) == 3)
	{
		sort_three(a, bench);
		return (1);
	}
	return (0);
}

void	run_algo(t_list **a, t_list **b, t_bench *bench, t_flags *flags)
{
	char	*algo;

	if (handle_small(a, bench))
		return ;
	algo = flags->algo;
	if (algo && ft_strncmp(algo, "--simple", 8) == 0)
	{
		simple_algo(a, b, bench);
		flags->algo = "Simple / O(n²)";
	}
	else if (algo && ft_strncmp(algo, "--medium", 8) == 0)
	{
		medium_algo(a, b, bench);
		flags->algo = "Medium / O(n√n)";
	}
	else if (algo && ft_strncmp(algo, "--complex", 9) == 0)
	{
		complex_algo_radix(a, b, bench);
		flags->algo = "Complex / O(nlogn)";
	}
	else
	{
		adaptive_algo(a, b, bench, flags);
	}
}
