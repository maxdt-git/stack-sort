/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:21:57 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 15:26:07 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s1;
	size_t			i;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = (unsigned char)c;
		i++;
	}
	return ((void *)s);
}

// #include <stdio.h>

// int	main (void)
// {
// 	char	test[20] = "Salut ca va";

// 	printf("Avant: %s\n", test);
// 	ft_memset(test, 'c', 12);
// 	printf("Apres: %s", test);
// }
