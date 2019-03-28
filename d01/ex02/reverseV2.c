/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:22:30 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/26 20:40:37 by emamenko         ###   ########.fr       */
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
	return (item);
}

void			push(struct s_stack *stack, char *word)
{
	struct s_item	*item;

	if ((item = malloc(sizeof(struct s_item))) == NULL)
		return ;
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack	*s;
	struct s_item	*item;

	s = stackInit();
	if (s == NULL)
		return ;
	while (lst)
	{
		push(s, lst->word);
		lst = lst->next;
	}
	while ((item = pop(s)) != NULL)
		printf("%s%s", item->word, item->next != NULL ? " ": "");
}
