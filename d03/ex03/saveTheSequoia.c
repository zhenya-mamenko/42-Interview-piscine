/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:56:08 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/29 20:55:51 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void saveTheSequoia(struct s_node **root)
{
	int	h;

	h = tree_height(*root);
	while (h-- > 0)
		heapify(root, NULL, 0);
}
