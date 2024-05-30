/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_pop_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:00:00 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/30 00:00:00 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

void	tree_pop_child(t_tree **parent)
{
	if (!(*parent) || !(*parent)->nb_child)
		return ;
	(*parent)->child->head->prev->as_tree->prev = NULL;
	deque_pop_left((*parent)->child);
	(*parent)->nb_child--;
}
