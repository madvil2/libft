/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_add_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:11 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/23 22:39:11 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

void	tree_add_child(t_tree **parent, void *content)
{
	t_tree	*new_node;

	if (!(*parent))
	{
		*parent = tree_node_init(content);
		return ;
	}
	new_node = tree_node_init(content);
	new_node->prev = (*parent);
	deque_push_node_left((*parent)->child, deque_node_init(new_node));
	(*parent)->nb_child++;
}
