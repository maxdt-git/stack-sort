/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:18:31 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 16:28:25 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = 0;
	srclen = 0;
	while (dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (size <= dstlen)
		return (size + srclen);
	i = 0;
	while (src[i] && i + dstlen < size - 1)
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*dst;
// 	char	*src;
// 	size_t	result;

// 	dst = "salut ca va ";
// 	src = "je suis au f6";
// 	result = ft_strlcat(dst, src, 10);
// 	printf("%ld", result);
// }
