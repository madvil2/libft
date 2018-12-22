/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcollio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:32:22 by pcollio-          #+#    #+#             */
/*   Updated: 2018/12/19 21:09:54 by pcollio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(words = (char **)malloc(sizeof(*words) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		j = 0;
		if (!(words[i] = ft_strnew(ft_word_len(&s[k], c))))
			ft_freearr(words, i);
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			words[i][j++] = s[k++];
		i++;
	}
	words[i] = NULL;
	return (words);
}
