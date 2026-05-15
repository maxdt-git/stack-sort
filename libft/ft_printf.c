/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:32:59 by mde-nas           #+#    #+#             */
/*   Updated: 2026/05/04 19:24:44 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	va;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	va_start(va, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
			{
				ret += ft_check(va, str[i]);
				i++;
			}
		}
		else
			ret += write(1, &str[i++], 1);
	}
	va_end(va);
	return (ret);
}
