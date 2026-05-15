/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 11:13:00 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/29 18:52:08 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(va_list arg, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (type == 'p')
		return (ft_point(va_arg(arg, void *)));
	if (type == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	if (type == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (type == 'u')
		return (ft_putnbr_unsi(va_arg(arg, unsigned int)));
	if (type == 'x')
		return (ft_print_hexa_low(va_arg(arg, unsigned int)));
	if (type == 'X')
		return (ft_print_hexa_upp(va_arg(arg, unsigned int)));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}
