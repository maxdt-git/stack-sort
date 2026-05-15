/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:32:39 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 17:48:09 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// void	*ft_memcpy(void *dest, const void *src, size_t n)
// {
// 	unsigned char		*d;
// 	const unsigned char	*s;
// 	size_t				i;

// 	d = (unsigned char *)dest;
// 	s = (const unsigned char *)src;
// 	i = 0;
// 	while (i < n)
// 	{
// 		d[i] = s[i];
// 		i++;
// 	}
// 	return (dest);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, lens1);
	ft_memcpy(result + lens1, s2, lens2 + 1);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*result;

// 	s1 = "salut ca va ";
// 	s2 = "je suis au f6";
// 	result = ft_strjoin(s1, s2);
// 	printf("%s", result);
// }
