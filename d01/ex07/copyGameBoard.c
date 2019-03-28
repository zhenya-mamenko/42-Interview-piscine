/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:26:48 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/27 18:48:21 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *get_random(struct s_node *node, t_list *list)
{
	while (list)
	{
		if (node == list->old)
			return (list->new);
		list = list->next;
	}
	return (NULL);
}

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *new, *res;
	t_list *list, *start;

	if (!node)
		return (NULL);
	res = NULL;
	start = NULL;
	list = NULL;
	new = NULL;
	while (node)
	{
		if (new)
		{
			new->next = malloc(sizeof(struct s_node));
			new = new->next;
		}
		else
			new = malloc(sizeof(struct s_node));
		if (!res)
			res = new;
		if (list)
		{
			list->next = malloc(sizeof(t_list));
			list = list->next;
		}
		else
			list = malloc(sizeof(t_list));
		if (!start)
			start = list;
		list->old = node;
		list->new = new;
		list->next = NULL;
		new->value = node->value;
		new->next = NULL;
		new->random = node->random;
		node = node->next;
	}
	new = res;
	while (new)
	{
		new->random = get_random(new->random, start);
		new = new->next;
	}
	return (res);
}
