/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:15:38 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 14:20:06 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s3;
	const unsigned char	*s4;
	size_t				i;

	s3 = (const unsigned char *)s1;
	s4 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s3[i] != s4[i])
			return ((unsigned char)s3[i] - (unsigned char)s4[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	int		result;

// 	s1 = "salut ca va";
// 	s2 = "salut cq va";
// 	result = ft_memcmp(s1, s2, 10);
// 	printf("%d", result);
// }
