/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 17:04:02 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/29 17:55:47 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexa(void *ptr)
{
	char				*hex;
	unsigned long int	nb;
	int					ret;

	hex = "0123456789abcdef";
	nb = (unsigned long)ptr;
	ret = 0;
	if (nb >= 16)
		ret += ft_hexa((void *)(nb / 16));
	ret += write(1, &hex[nb % 16], 1);
	return (ret);
}

int	ft_point(void *ptr)
{
	int	ret;

	ret = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	ret += write(1, "0x", 2);
	ret += ft_hexa(ptr);
	return (ret);
}
