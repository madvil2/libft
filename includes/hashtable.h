/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:57:12 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/30 09:57:12 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H
# define HASHTABLE_H

# include "libft.h"

typedef struct s_ht
{
	char	**key;
	char	**value;
	int		nb_entry;
	int		size;
}	t_ht;

//hash.c
void	ht_print(t_ht *ht);
int		wlfsbrg12(const char *str);

//hashtable.c
t_ht	*ht_init(int size);
void	ht_resize(t_ht *ht);
void	ht_delete(t_ht *ht, char *key);
char	*ht_get(t_ht *ht, char *key);
void	ht_add(t_ht *ht, char *key, char *value);

#endif