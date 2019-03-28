/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:24:21 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 14:54:32 by emamenko         ###   ########.fr       */
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

char *dequeue(struct s_queue *queue)
{
	struct s_node	*n;

	n = queue->first;
	if (!n)
		return (NULL);
	queue->first = n->next;
	return (n->message);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node	*n;

	if ((n = malloc(sizeof(struct s_node))) == NULL)
		return ;
	n->message = strdup(message);
	n->next = NULL;
	if (isEmpty(queue))
	{
		queue->first = queue->last = n;
	}
	else
	{
		queue->last->next = n;
		queue->last = n;
	}
}

char *peek(struct s_queue *queue)
{
	return (queue->first ? queue->first->message : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return (queue->first ? 0 : 1);
}
