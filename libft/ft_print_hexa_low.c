/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:21:32 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/29 22:13:26 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexa_low(unsigned int n)
{
	char			*hex;
	unsigned long	nb;
	int				ret;

	hex = "0123456789abcdef";
	nb = (unsigned long)n;
	ret = 0;
	if (nb >= 16)
		ret += ft_print_hexa_low(nb / 16);
	ret += write(1, &hex[nb % 16], 1);
	return (ret);
}
