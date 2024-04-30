/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:56:09 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/30 06:56:09 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hashtable.h"

static unsigned int	wlfsbrg12(const char *str)
{
	unsigned int	hash;
	int				i;

	i = -1;
	while (str[++i])
		hash = hash * 47 + str[i];
	return (hash);
}

t_ht	*ht_resize(t_ht *ht)
{
	int		new_size;
	t_ht	*new_ht;

	new_size = ht->size * 2;
	new_ht = ft_calloc(new_size, sizeof(t_ht));
	ft_memcpy(new_ht, ht, ht->size * sizeof(t_ht));
	free(ht);
	return (new_ht);
}

void	ht_delete(t_ht *ht, char *key)
{
	unsigned int	hash;
	int				ht_size;
	int				key_len;
	int				counter;

	counter = 0;
	key_len = ft_strlen(key);
	ht_size = ht->size;
	hash = wlfsbrg12(key);
	while (!ht->key[hash % ht_size]
		|| ft_strncmp(ht->key[hash % ht_size], key, key_len))
	{
		hash++;
		counter++;
		if (counter == ht_size)
			return ;
	}
	free(ht->key[hash % ht_size]);
	free(ht->value[hash % ht_size]);
	ht->key[hash % ht_size] = NULL;
	ht->value[hash % ht_size] = NULL;
}

char	*ht_get(t_ht *ht, char *key)
{
	unsigned int	hash;
	int				ht_size;
	int				key_len;
	int				counter;

	counter = 0;
	key_len = ft_strlen(key);
	ht_size = ht->size;
	hash = wlfsbrg12(key);
	while (!ht->key[hash % ht_size]
		|| ft_strncmp(ht->key[hash % ht_size], key, key_len))
	{
		hash++;
		counter++;
		if (counter == ht_size)
			return (NULL);
	}
	return (ht->value[hash % ht_size]);
}

void	ht_add(t_ht *ht, char *key, char *value)
{
	unsigned int	hash;
	int				ht_size;

	ht_size = ht->size;
	hash = wlfsbrg12(key);
	while (ht->key[hash % ht_size])
		hash++;
	ht->key[hash] = key;
	ht->value[hash] = value;
}
