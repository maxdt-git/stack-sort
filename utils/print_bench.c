/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlepain <charlene.lepain@learner.42.te    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:20:09 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/07 19:20:11 by chlepain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_ops(t_bench *bench)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench, float disorder, char *strategy)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd((int)(disorder * 10000) % 100, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	print_bench_ops(bench);
}
