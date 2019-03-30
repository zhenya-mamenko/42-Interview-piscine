/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:18:03 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 00:58:46 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_blocks	*make_blocks(struct s_stone *s, int c)
{
	t_blocks	*b;
	int			i, l;

	if ((b = malloc(sizeof(t_blocks) * c)) == NULL)
		return (NULL);
	i = l = -1;
	while (s)
	{
		if (s->size != l)
		{
			i++;
			l = s->size;
			b[i].b = s;
			b[i].size = l;
		}
		b[i].e = s;
		s = s->next;
	}
	return (b);
}

void sortStones(struct s_stone **stone)
{
	struct s_stone	*s, *q;
	int				count, l, i, j;
	t_blocks		*b, tmp;

	s = *stone;
	count = 0;
	l = 0;
	while (s)
	{
		if (l != s->size)
		{
			l = s->size;
			count += 1;
		}
		s = s->next;
	}
	s = *stone;
	b = make_blocks(s, count);
	i = 1;
	while (i < count)
	{
		j = 0;
		while (j < count - i)
		{
			if (b[j].size > b[j + 1].size)
			{
				tmp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	s = NULL;
	while (i < count)
	{
		while (b[i].b)
		{
			if (s == NULL)
			{
				q = malloc(sizeof(struct s_stone));
				s = q;
			}
			else
			{
				q->next = malloc(sizeof(struct s_stone));
				q = q->next;
			}
			if (q == NULL)
				return ;
			q->size = b[i].b->size;
			q->next = NULL;
			if (b[i].b == b[i].e)
				break ;
			b[i].b = b[i].b->next;
		}
		i++;
	}
	free(*stone);
	*stone = s;
}
