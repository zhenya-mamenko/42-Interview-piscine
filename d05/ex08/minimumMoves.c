/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:10:07 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/03 20:36:56 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_move	*create_move(struct s_node *node, int move)
{
	struct s_move	*m;

	m = malloc(sizeof(struct s_move));
	m->n = node;
	m->move = move;
	return (m);
}

int				minimumMoves(struct s_node *node)
{
	struct s_queue	*q = queueInit();
	struct s_move	*m;

	enqueue(q, create_move(node, 0));
	while (q->first)
	{
		m = (struct s_move *)dequeue(q);
		if (m->n->isFinal)
			return (m->move);
		if (m->n->next)
			enqueue(q, create_move(m->n->next, m->move + 1));
		if (m->n->random)
			enqueue(q, create_move(m->n->random, m->move + 1));
	}
	return (m->move);
}
