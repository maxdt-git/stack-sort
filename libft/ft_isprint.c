/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:10:58 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 15:23:37 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test[20] = "salut\n ca va 18432";

// 	printf("%d", ft_isprint(test[6]));
// }
