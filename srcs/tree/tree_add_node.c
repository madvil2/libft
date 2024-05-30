/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_add_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:29:00 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/30 00:29:00 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

void	tree_add_node(t_tree **parent, t_tree *new_node)
{
	if (!(*parent))
	{
		*parent = new_node;
		return ;
	}
	new_node->prev = (*parent);
	deque_push_node_left((*parent)->child, deque_node_init(new_node));
	(*parent)->nb_child++;
}
