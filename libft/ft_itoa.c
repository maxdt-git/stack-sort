/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:42:11 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 19:00:35 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	new_size(long n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	fill_str(char *str, long n, int len)
{
	int	start;

	start = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		start = 1;
	}
	while (len >= start)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = (long)n;
	len = new_size(nb);
	if (nb == 0)
		len = 1;
	else if (nb < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_str(str, nb, len - 1);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*test;

// 	test = "2123";
// 	printf("le resultat est: %s", ft_itoa(test));
// }
