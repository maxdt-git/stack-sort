/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-nas <maxdenasdetourris@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:05:39 by mde-nas           #+#    #+#             */
/*   Updated: 2026/04/23 15:11:44 by mde-nas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(const char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c))
			i++;
		if (s[i] && !check_sep(s[i], c))
		{
			words++;
			while (s[i] && !check_sep(s[i], c))
				i++;
		}
	}
	return (words);
}

static char	*copy_words(const char *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && !check_sep(s[i], c))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !check_sep(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	memfree(char **tab, size_t i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	i;
	size_t	j;

	final = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!final)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c))
			i++;
		if (s[i] && !check_sep(s[i], c))
		{
			final[j] = copy_words(&s[i], c);
			if (!final[j])
				return (memfree(final, j), NULL);
			j++;
			while (s[i] && !check_sep(s[i], c))
				i++;
		}
	}
	final[j] = '\0';
	return (final);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**tab;
// 	int	i;

// 	i = 0;
// 	tab = ft_split("", ',');
// 	if (!tab)
// 		return (0);
// 	while (tab[i])
// 	{
// 		printf("Mot %d : %s\n", i, tab[i]);
// 		i++;
// 	}
// }
