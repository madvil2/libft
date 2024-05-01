/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:00:23 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/01 10:00:23 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hashtable.h"

int	wlfsbrg12(const char *str)
{
	unsigned int	hash;
	int				i;

	i = -1;
	hash = 'g' + 'u' + 'i' + 'l' + 'o' + 'm' + 'l' + 'o' + 'h';
	while (str[++i])
		hash = (hash + str[i]) * 47;
	return (hash);
}

void	ht_print(t_ht *ht)
{
	int	i;

	i = -1;
	while (++i < ht->size)
		if (ht->key[i])
			ft_printf("hash: %i key: %s value: %s\n", i,
				ht->key[i], ht->value[i]);
}
