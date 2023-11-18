/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokaimov <kokaimov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:34:16 by kokaimov          #+#    #+#             */
/*   Updated: 2023/11/17 16:10:25 by kokaimov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static int	count_letters(char const *s, char c, int n)
{
	int	i;
	int	count;
	int	res;

	i = 0;
	count = -1;
	res = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		if (count == n && s[i] != c)
			res++;
		if (count > n)
			return (res);
		i++;
	}
	return (res);
}

static void	save_word(char const *s, char c, int n, char *res)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = -1;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			count++;
		if (count == n && s[i] != c)
			res[j++] = s[i];
		if (count > n)
			return ;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_counter;
	int		i;

	if (!s)
		return (NULL);
	words_counter = count_words(s, c);
	res = ft_calloc((words_counter + 1), sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words_counter)
	{
		res[i] = ft_calloc(count_letters(s, c, i) + 1, sizeof(char));
		if (!res[i])
		{
			while (--i)
				free(res[i]);
			free(res);
			return (NULL);
		}
		save_word(s, c, i, res[i]);
		i++;
	}
	return (res);
}
