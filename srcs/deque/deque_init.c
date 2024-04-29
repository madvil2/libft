/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 06:04:06 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 06:04:06 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/deque.h"

t_deque	*deque_init(void)
{
	t_deque	*res;

	res = malloc(sizeof(t_deque));
	res->head = NULL;
	res->size = 0;
	return (res);
}
