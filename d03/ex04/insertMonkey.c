/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertMonkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:01:03 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/30 21:09:24 by emamenko         ###   ########.fr       */
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

int isEmpty(struct s_queue *queue)
{
	return (queue->first ? 0 : 1);
}

struct s_node *dequeue(struct s_queue *queue)
{
	struct s_qnode	*n;

	n = queue->first;
	if (!n)
		return (NULL);
	queue->first = n->next;
	return (n->value);
}

void enqueue(struct s_queue *queue, struct s_node *value)
{
	struct s_qnode	*n;

	if ((n = malloc(sizeof(struct s_qnode))) == NULL)
		return ;
	n->value = value;
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

int		tree_height(struct s_node *el)
{
	int		max;
	int		count;

	count = 0;
	max = 0;
	if (el && el->left)
	{
		count = tree_height(el->left) + 1;
		if (count > max)
			max = count;
	}
	if (el && el->right)
	{
		count = tree_height(el->right) + 1;
		if (count > max)
			max = count;
	}
	return (max);
}

int heapify(struct s_node **a, struct s_node *p, int side)
{
	struct s_node *n, *t;

	if (!(*a))
		return (1);
	if ((*a)->left)
	{
		if (heapify(&((*a)->left), *a, 1) == 0)
			return (0);
		if ((*a)->left->value > (*a)->value)
		{
			n = (*a);
			t = (*a)->right;
			(*a) = (*a)->left;
			n->right = (*a)->right;
			n->left = (*a)->left;
			(*a)->left = n;
			(*a)->right = t;
			if (side == 1)
				p->left = *a;
			else if (side == 2)
				p->right = *a;
		}
	}
	if ((*a)->right)
	{
		if (heapify(&((*a)->right), *a, 2) == 0)
			return (0);
		if ((*a)->right->value > (*a)->value)
		{
			n = (*a);
			t = (*a)->left;
			(*a) = (*a)->right;
			n->right = (*a)->right;
			n->left = (*a)->left;
			(*a)->right = n;
			(*a)->left = t;
			if (side == 1)
				p->left = *a;
			else if (side == 2)
				p->right = *a;
		}
	}
	return (1);
}

void find_place(struct s_node *monkey, struct s_queue *q)
{
	struct s_node *n;

	while (isEmpty(q) == 0)
	{
		n = dequeue(q);
		if (n->left)
			enqueue(q, n->left);
		else
		{
			n->left = monkey;
			return ;
		}
		if (n->right)
			enqueue(q, n->right);
		else
		{
			n->right = monkey;
			return ;
		}
	}
}

void insertMonkey(struct s_node **root, struct s_node *monkey)
{
	int	h;
	struct s_queue *q;

	q = queueInit();
	enqueue(q, *root);
	find_place(monkey, q);
	h = tree_height(*root);
	while (h-- > 0)
		heapify(root, NULL, 0);
}