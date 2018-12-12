/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:32:22 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/13 00:26:16 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (words);
}

static int	word_len(char const *s, char c)
{
	int len;

	len = 0;
	while (*s && *s != '\0')
		while (*s != c && *s != '\0')
			len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		nwords;

	i = 0;
	nwords = count_words(s, c);
	if (!s && (words = (char **)malloc(sizeof(*words) * nwords + 1) == NULL)
		return (NULL);
	while (i < nwords)
	{
		while (*s == c)
			s++;
		if (!(words[i] = ft_strnew(word_len(s, c))))
			words[i] = NULL;
	}
}
