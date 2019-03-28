/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 19:37:49 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/26 20:12:48 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node	*create_list(void)
{
	size_t		i;
	struct s_node *f, *n, *p;

	i = 0;
	f = p = NULL;
	while (i < strlen(CS))
	{
		if ((n = malloc(sizeof(struct s_node))) == NULL)
			return (NULL);
		n->c = CS[i];
		n->prev = n->next = NULL;
		if (f == NULL)
			f = n;
		if (p != NULL)
		{
			p->next = n;
			n->prev = p;
		}
		p = n;
		i++;
	}
	p->next = f;
	f->prev = p;
	return (f);
}

void			wheel(struct s_node **n, int w)
{
	if (w > 0)
	{
		while (w-- > 0)
			(*n) = (*n)->next;
	}
	else if (w < 0)
	{
		while (w++ < 0)
			(*n) = (*n)->prev;
	}
}

char			*precious(int *text, int size)
{
	int		i;
	char	*s;
	struct s_node *n;

	if ((n = create_list()) == NULL)
		return (NULL);
	if ((s = malloc(size + 1)) == NULL)
		return (NULL);
	s[size] = '\0';
	i = 0;
	while (i < size)
	{
		wheel(&n, text[i]);
		s[i] = n->c;
		i++;
	}
	return (s);
}
