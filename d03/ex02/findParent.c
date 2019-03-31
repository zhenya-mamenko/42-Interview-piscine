/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:56:41 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/29 13:52:18 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack	*stackInit(void)
{
	struct s_stack	*s;

	if ((s = malloc(sizeof(struct s_stack))) == NULL)
		return (NULL);
	s->item = NULL;
	return (s);
}

void			*pop(struct s_stack *stack)
{
	struct s_item	*item;

	if (stack->item == NULL)
		return (NULL);
	item = stack->item;
	stack->item = stack->item->next;
	return (item->node);
}

void			push(struct s_stack *stack, struct s_node *node)
{
	struct s_item	*item;

	if ((item = malloc(sizeof(struct s_item))) == NULL)
		return ;
	item->node = node;
	item->next = stack->item;
	stack->item = item;
}

int				find_me(struct s_node *root, char *s, struct s_stack *q)
{
	int		i;

	if (!root)
		return (0);
	i = 0;
	while (root->children[i])
	{
		if (strcmp(root->children[i]->name, s) == 0)
		{
			push(q, root);
			// printf("%s\n", root->children[i]->name);
			return (1);
		}
		else if (find_me(root->children[i], s, q) == 1)
		{
			push(q, root->children[i]);
			// printf("%s\n", root->children[i]->name);
			return (1);
		}
		i++;
	}
	return (0);
}

struct s_node	*findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	struct s_stack *q1, *q2;
	struct s_node *n1, *n2, *p;

	q1 = stackInit();
	q2 = stackInit();
	//printf("looking for: %s\n", firstSpecies);
	if (find_me(root, firstSpecies, q1) == 0)
		return (0);
	//printf("\nlooking for: %s\n", secondSpecies);
	if (find_me(root, secondSpecies, q2) == 0)
		return (0);
	p = NULL;
	while (q1->item && q2->item)
	{
		n1 = pop(q1);
		// printf("\nq1: %s\n", n1->name);
		n2 = pop(q2);
		// printf("\nq2: %s\n", n2->name);
		if (strcmp(n1->name, n2->name) != 0)
			return(p) ;
		p = n1;
	}
	// printf("\n\n");
	return (p);
}
