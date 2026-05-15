/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:59:30 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 18:31:50 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			srclen;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dst[20] = "salut ca va ";
// 	char	*src;
// 	size_t	result;

// 	src = "je suis au f6";
// 	result = ft_strlcpy(dst, src, 5);
// 	printf("%ld", result);
// }
