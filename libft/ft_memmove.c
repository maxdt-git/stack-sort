/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:45:25 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 18:19:56 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s || d > s + n)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n ;
		while (i-- > 0)
			d[i] = s[i];
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	d[20] = "Salut ca va ";
// 	char	*s;
// 	char	*result;

// 	s = "tranquille et toi";
// 	result = ft_memmove(d, s, 10);
// 	printf("%s", result);
// }
