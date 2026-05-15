/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:42:36 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 16:17:17 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;
	size_t		i;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			last = &s[i];
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return ((char *)last);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;
// 	char	*result;

// 	s = "salut ca va";
// 	result = ft_strrchr(s, 'l');
// 	printf("%s", result);
// }
