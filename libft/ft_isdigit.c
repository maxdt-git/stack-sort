/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:10:50 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/22 15:19:38 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	test[20] = "salut ca va 18432";

// 	printf("%d", ft_isdigit(test[1]));
// }
