/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:28:48 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/29 17:58:50 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsi(unsigned long n)
{
	char	c;
	int		ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putnbr_unsi((n / 10));
	c = '0' + (n % 10);
	ret += write(1, &c, 1);
	return (ret);
}
