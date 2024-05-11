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

t_ht	*ht_init(int size)
{
	t_ht	*ht;

	ht = ft_malloc(sizeof(ht));
	ht->size = size;
	ht->nb_entry = 0;
	ht->key = ft_calloc(ht->size, sizeof(char **));
	ht->value = ft_calloc(ht->size, sizeof(char **));
	return (ht);
}

void	ht_resize(t_ht *ht)
{
	int		new_size;
	char	**new_key;
	char	**new_value;

	new_size = ht->size * 2;
	new_key = ft_calloc(new_size, sizeof(char *));
	new_value = ft_calloc(new_size, sizeof(char *));
	ft_memcpy(new_key, ht->key, ht->size * sizeof(char *));
	ft_memcpy(new_value, ht->value, ht->size * sizeof(char *));
	free(ht->key);
	free(ht->value);
	ht->key = new_key;
	ht->value = new_value;
	ht->size = new_size;
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
		|| ft_strncmp(ht->key[hash % ht_size], key, key_len + 1))
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
	ht->nb_entry--;
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
		|| ft_strncmp(ht->key[hash % ht_size], key, key_len + 1))
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

	if (ht->nb_entry == ht->size)
		ht_resize(ht);
	ht_size = ht->size;
	hash = wlfsbrg12(key);
	while (ht->key[hash % ht_size])
	{
		if (!ft_strncmp(ht->key[hash % ht_size], key, ft_strlen(key) + 1))
		{
			ht->value[hash % ht_size] = value;
			return ;
		}
			hash++;
	}
	ht->key[hash % ht_size] = key;
	ht->value[hash % ht_size] = value;
	ht->nb_entry++;
}
