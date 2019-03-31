/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 23:32:25 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/29 00:24:12 by emamenko         ###   ########.fr       */
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

int		tree_max(struct s_node *el)
{
	int		max;
	int		tmp;

	tmp = 0;
	max = el ? el->value : 0;
	if (el && el->left)
	{
		tmp = tree_max(el->left);
		if (tmp > max)
			max = tmp;
	}
	if (el && el->right)
	{
		tmp = tree_max(el->right);
		if (tmp > max)
			max = tmp;
	}
	return (max);
}

int		tree_min(struct s_node *el)
{
	int		min;
	int		tmp;

	tmp = 0;
	min =  el ? el->value : 0;
	if (el && el->left)
	{
		tmp = tree_min(el->left);
		if (tmp < min)
			min = tmp;
	}
	if (el && el->right)
	{
		tmp = tree_min(el->right);
		if (tmp < min)
			min = tmp;
	}
	return (min);
}

int		tree_count(struct s_node *el)
{
	int		tmp;
	int		count;

	if (!el)
		return (0);
	count = 1;
	tmp = 0;
	if (el && el->left)
	{
		tmp = tree_count(el->left);
		count += tmp;
	}
	if (el && el->right)
	{
		tmp = tree_count(el->right);
		count += tmp;
	}
	return (count);
}

int		tree_bst(struct s_node *el)
{
	int		tmp;
	int		bst;

	if (!el)
		return (0);
	bst = 1;
	tmp = 0;
	if (el && el->left)
	{
		bst = el->value >= el->left->value ? 1 : 0;
		tmp = tree_bst(el->left);
		bst &= tmp;
	}
	if (el && el->right)
	{
		bst = el->value < el->right->value ? 1 : 0;
		tmp = tree_bst(el->right);
		bst &= tmp;
	}
	return (bst);
}

int		tree_balanced(struct s_node *el)
{
	int		left, right, b;

	left = 0;
	right = 0;
	if (el && el->left)
	{
		left = tree_balanced(el->left);
		left = left != -1 ? left + 1 : -1;
	}
	if (el && el->right)
	{
		right = tree_balanced(el->right);
		right = right != -1 ? right + 1 : -1;
	}
	b = (left == -1 || right == -1 ? -1 : (right > left ? right - left : left - right) < 2 ? left + right : -1);
	return (b);
}

struct s_info getInfo(struct s_node *root)
{
	struct s_info	i;

	i.height = tree_height(root);
	i.max = tree_max(root);
	i.min = tree_min(root);
	i.elements = tree_count(root);
	i.isBST = tree_bst(root);
	i.isBalanced = tree_balanced(root) != -1 ? 1 : 0;
	return (i);
}
