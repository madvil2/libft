/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam-vu <nam-vu@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:19:17 by nam-vu            #+#    #+#             */
/*   Updated: 2024/05/23 22:19:17 by nam-vu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H
#include "deque.h"

typedef struct s_tree	t_tree;
typedef struct s_ast_node	t_ast_node;
typedef struct s_token		t_token;
typedef struct s_nonterm	t_nonterm;

struct	s_tree
{
	t_tree			*prev;
	t_deque			*child;
	int				nb_child;
	union
	{
		void		*as_ptr;
		char		*as_str;
		t_token		*as_token;
		t_ast_node	*as_ast_node;
		t_nonterm	*as_nt;
		long		as_long;
		int			as_int;
		char		as_char;
	};
};

t_tree	*tree_node_init(void *content);
void	tree_add_child(t_tree **parent, void *content);
void	tree_pop_child(t_tree **parent);
void	tree_add_node(t_tree **parent, t_tree *new_node);

#endif