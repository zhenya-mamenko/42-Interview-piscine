/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:03:26 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/05 22:28:36 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_deque *dequeInit(void)
{
	struct s_deque	*q;

	if ((q = malloc(sizeof(struct s_deque))) == NULL)
		return (NULL);
	q->first = q->last = NULL;
	return (q);
}

int popFront(struct s_deque *queue)
{
	struct s_dequeNode	*n;

	n = queue->first;
	if (!n)
		return (INT32_MIN);
	queue->first = n->next;
	if (queue->first == NULL)
		queue->last = NULL;
	return (n->value);
}

int popBack(struct s_deque *queue)
{
	struct s_dequeNode	*n;

	n = queue->last;
	if (!n)
		return (INT32_MIN);
	queue->last = n->prev;
	if (queue->last == NULL)
		queue->first = NULL;
	return (n->value);
}

void pushBack(struct s_deque *queue, int value)
{
	struct s_dequeNode	*n;

	if ((n = malloc(sizeof(struct s_dequeNode))) == NULL)
		return ;
	n->value = value;
	n->next = NULL;
	n->prev = NULL;
	if (queue->first == NULL)
	{
		queue->first = queue->last = n;
	}
	else
	{
		queue->last->next = n;
		n->prev = queue->last;
		queue->last = n;
	}
}

void pushFront(struct s_deque *queue, int value)
{
	struct s_dequeNode	*n;

	if ((n = malloc(sizeof(struct s_dequeNode))) == NULL)
		return ;
	n->value = value;
	n->next = NULL;
	if (queue->first == NULL)
	{
		queue->first = queue->last = n;
	}
	else
	{
		queue->first->prev = n;
		n->next = queue->first;
		queue->first = n;
	}
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	struct s_deque	*q;
	struct s_max	*m;
	int				tmp;


	q = dequeInit();
	if ((m = malloc(sizeof(struct s_max))) == NULL)
		return (NULL);
	m->length = n - k + 1;
	if ((m->max = malloc(sizeof(int) * m->length)) == NULL)
		return (NULL);
	tmp = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		if (i >= k)
		{
			m->max[i - k] = popFront(q);
			if (arr[i - k] == m->max[i - k])
			{
				tmp = popBack(q);
			}
		}
		if (arr[i] > tmp)
		{
			tmp = arr[i];
		}
		else
			pushBack(q, arr[i]);
		pushFront(q, tmp);

	}
	m->max[n - k] = tmp;
	return (m);
}
