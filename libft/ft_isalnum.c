/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:55:47 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 15:16:04 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalpha(int c)
// {
// 	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
// 		return (1);
// 	return (0);
// }

// int	ft_isdigit(int c)
// {
// 	if (c <= 57 && c >= 48)
// 		return (1);
// 	return (0);
// }

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test[20] = "salut ca va";

// 	printf("%d", ft_isalnum(test[3]));
// }
