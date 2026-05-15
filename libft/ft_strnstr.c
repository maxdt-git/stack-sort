/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:29:19 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 18:27:06 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	littlelen;

	if (!little)
		return ((char *)big);
	littlelen = 0;
	while (little[littlelen])
		littlelen++;
	if (littlelen == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i + littlelen <= len)
	{
		j = 0;
		while (j < littlelen && big[i + j] == little[j])
			j++;
		if (j == littlelen)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*big;
// 	char	*little;

// 	big = "salut ca va";
// 	little = "";
// 	printf("%s", ft_strnstr(big, little, 10));
// }
