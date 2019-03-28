/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:43:40 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/27 12:22:13 by emamenko         ###   ########.fr       */
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

int			pop(struct s_stack *stack)
{
	struct s_item	*item;

	if (stack->item == NULL)
		return (0);
	item = stack->item;
	stack->item = stack->item->next;
	return (item->idx);
}

void			push(struct s_stack *stack, int idx)
{
	struct s_item	*item;

	if ((item = malloc(sizeof(struct s_item))) == NULL)
		return ;
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

char			*console(void)
{
	char	*message, input[256];
	struct s_stack	*s;
	int		l;

	s = stackInit();
	memset(&input[0], 0, 256);
	while (1)
	{
		printf("...> ");
		l = strlen(input);
		fgets(&input[l], 255 - l, stdin);
		if (strcmp("UNDO", &input[l]) == 0 || strcmp("UNDO\n", &input[l]) == 0)
		{
			l = pop(s);
			input[l] = '\0';
		}
		else if (strcmp("SEND", &input[l]) == 0 || strcmp("SEND\n", &input[l]) == 0)
		{
			input[l] = '\0';
			break ;
		}
		else
			push(s, l);
		printf("%s\n", input);
		l = strlen(input);
		if (input[l - 1] == '\n')
			input[l - 1] = '\0';
	}
	if ((message = malloc(strlen(input) + 1)) == NULL)
		return (NULL);
	strcpy(message, input);
	return (message);
}
