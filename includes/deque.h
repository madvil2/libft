/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 06:04:20 by nam-vu            #+#    #+#             */
/*   Updated: 2024/04/27 06:04:20 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include <stdbool.h>
# include "libft.h"

typedef struct s_deque		t_deque;
typedef struct s_deque_node	t_deque_node;
typedef struct s_ast_node	t_ast_node;
typedef struct s_token		t_token;

struct	s_deque_node
{
	t_deque_node	*prev;
	t_deque_node	*next;
	union
	{
		void		*as_ptr;
		char		*as_str;
		t_token		*as_token;
		t_ast_node	*as_ast_node;
		long		as_long;
		int			as_int;
		char		as_char;
	};
};

struct	s_deque
{
	t_deque_node	*head;
	int				size;
};

t_deque			*deque_init(void);
void			deque_iter(t_deque *deque, void (*f)(void *ptr));
t_deque_node	*deque_node_init(void *content);
t_deque_node	*deque_pop_left(t_deque *deque);
t_deque_node	*deque_pop_right(t_deque *deque);
void			deque_push_node_left(t_deque *deque, t_deque_node *node);
void			deque_push_node_right(t_deque *deque, t_deque_node *node);
void			deque_rotate(t_deque *deque, int n);
void			deque_swap(t_deque *deque);
void			deque_sort(t_deque *deque, int (cmp)(void *ptr1, void *ptr2));
void			deque_print(t_deque *deque);
void			**deque_to_arr(t_deque *deque);

#endif