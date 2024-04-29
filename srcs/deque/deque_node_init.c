/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_node_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 07:14:08 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 07:14:08 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

t_deque_node	*deque_node_init(void *content)
{
	t_deque_node	*res;

	res = malloc(sizeof(t_deque_node));
	res->next = res;
	res->prev = res;
	res->as_ptr = content;
	return (res);
}
