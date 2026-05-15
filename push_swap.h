/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 10:29:00 by chlepain          #+#    #+#             */
/*   Updated: 2026/05/08 14:05:12 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

typedef struct s_flags
{
	int			flag_start;
	int			bench_mode;
	char		*algo;
	float		disorder;
}	t_flags;

// fonctions de tri
float	compute_disorder(t_list *stack_a);
void	sa(t_list **stack_a, t_bench *bench);
void	sb(t_list **stack_b, t_bench *bench);
void	ss(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	pa(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	pb(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	ra(t_list **stack_a, t_bench *bench);
void	rb(t_list **stack_b, t_bench *bench);
void	rr(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	rra(t_list **stack_a, t_bench *bench);
void	rrb(t_list **stack_b, t_bench *bench);
void	rrr(t_list **stack_a, t_list **stack_b, t_bench *bench);

// helpers
int		good_order(t_list *stack);
int		is_number(char *str);
int		is_sign(char c);
int		dupplicate(t_list *stack);
t_list	*build_stack(int ac, char **av, int start);

// simple algo
void	simple_algo(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	sort_two(t_list **stack, t_bench *bench);
void	sort_three(t_list **stack, t_bench *bench);
long	find_min_pos(t_list *stack);
void	rotate_min(t_list **stack, t_bench *bench);
void	sort_five(t_list **stack_a, t_list **stack_b, t_bench *bench);

// medium algo
void	medium_algo(t_list **stack_a, t_list **stack_b, t_bench *bench);
long	find_min_chunk(t_list *stack, int chunk);
long	find_max_pos(t_list *stack);
void	rotate_max(t_list **stack, t_bench *bench);
void	push_chunk(t_list **stack_a, t_list **stack_b, t_bench *bench,
			int chunk);

// adaptive algo
void	low_algo(t_list **stack_a, t_bench *bench);
void	adaptive_algo(t_list **stack_a, t_list **stack_b, t_bench *bench,
			t_flags *flags);

// complex algo
void	complex_algo_radix(t_list **stack_a, t_list **stack_b, t_bench *bench);
void	ft_sort_long_tab(long *tab, long size);
void	fill_tmp_rank(t_list *stack_a, long *new_tab, long size);
void	change_value_rank(t_list **stack_a);
int		get_bit_count(long size);

// bench
t_flags	parse_flags(char **av);
void	print_bench(t_bench *bench, float disorder, char *strategy);
void	init_bench(t_bench *bench);
void	run_algo(t_list **a, t_list **b, t_bench *bench, t_flags *flags);

#endif
