/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_node_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:32:04 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/23 22:32:04 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tree.h"

t_tree	*tree_node_init(void *content)
{
	t_tree	*res;

	res = malloc(sizeof(t_tree));
	res->prev = NULL;
	res->child = deque_init();
	res->nb_child = 0;
	res->as_ptr = content;
	return (res);
}
