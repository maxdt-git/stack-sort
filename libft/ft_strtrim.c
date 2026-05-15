/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 09:40:49 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/23 10:16:18 by mde-nas          ###   ########.fr       */
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

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if ((unsigned char)s[i] == (unsigned char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if ((unsigned char)c == '\0')
// 		return ((char *)&s[i]);
// 	return (NULL);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substring;
// 	size_t	i;
// 	size_t	slen;

// 	if (!s)
// 		return (NULL);
// 	slen = ft_strlen(s);
// 	if (start >= slen)
// 		len = 0;
// 	else if (len > slen - start)
// 		len = slen - start;
// 	substring = malloc(sizeof(char) * (len + 1));
// 	if (!substring)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		substring[i] = s[start + i];
// 		i++;
// 	}
// 	substring[i] = '\0';
// 	return (substring);
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trim = ft_substr(s1, start, end - start);
	return (trim);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[20] = "cava salut cava";
// 	char	*result;

// 	result = ft_strtrim(s, "cava");
// 	printf("%s", result);
// }
