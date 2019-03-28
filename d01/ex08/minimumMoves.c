/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimumMoves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:54:05 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/27 19:14:50 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue	*q;

	if ((q = malloc(sizeof(struct s_queue))) == NULL)
		return (NULL);
	q->first = q->last = NULL;
	return (q);
}

struct s_node *dequeue(struct s_queue *queue)
{
	struct s_node	*n;

	n = queue->first;
	if (!n)
		return (NULL);
	queue->first = n->next;
	return (n);
}

void enqueue(struct s_queue *queue, struct s_node *node)
{
	if (isEmpty(queue))
	{
		queue->first = queue->last = node;
	}
	else
	{
		queue->last->next = node;
		queue->last = node;
	}
}

int isEmpty(struct s_queue *queue)
{
	return (queue->first ? 0 : 1);
}

int minimumMoves(struct s_node *node)
{
	int count;
	struct s_queue	*q;
	struct s_node *n;

	count = 0;
	q = queueInit();
	enqueue(q, node);
	while (!isEmpty(q))
	{
		n = dequeue(q);
		if (n->isFinal)
			break;
		if (n->next)
			enqueue(q, n->next);
		if (n->random && n->random != n)
			enqueue(q, n->random);
		count += 1;
	}
	return (count);
}
