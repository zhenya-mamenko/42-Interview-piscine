/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   understand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 10:46:49 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/30 11:04:15 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cmp(char *a, char *b)
{
	int				c;

	c = strcmp(a, b);
	return (c);
}

void		ft_qsort(char **a, size_t cnt,
	int f(char *, char *))
{
	size_t	med;
	t_hilo	b;
	t_hilo	fl;
	char *tmp;

	if (cnt < 2)
		return ;
	med = cnt >> 1;
	HILO(b, cnt - 1, 0);
	HILO(fl, 1, 1);
	while (b.l < med && b.h > med)
	{
		b.l += (fl.l = (f(a[b.l], a[med]) < 0) && fl.l);
		b.h -= (fl.h = (f(a[b.h], a[med]) > 0) && fl.h);
		if (!fl.l && !fl.h)
		{
			tmp = a[b.l];
			a[b.l] = a[b.h];
			a[b.h] = tmp;
			b.l++;
			HILO(fl, 1, 1);
		}
	}
	while (med > b.l)
		if (f(a[med], a[med - 1]) < 0)
		{
			tmp = a[med - 1];
			a[med - 1] = a[med];
			a[med] = tmp;
			med--;
		}
		else
		{
			tmp = a[med - 1];
			a[med - 1] = a[b.l];
			a[b.l] = tmp;
			b.l++;
		}
	while (med < b.h)
		if (f(a[med], a[med + 1]) > 0)
		{
			tmp = a[med + 1];
			a[med + 1] = a[med];
			a[med] = tmp;
			med++;
		}
		else
		{
			tmp = a[med + 1];
			a[med + 1] = a[b.h];
			a[b.h] = tmp;
			b.h--;
		}
	ft_qsort(a, med, f);
	ft_qsort(a + med + 1, cnt - med - 1, f);
}

struct s_trie *createTrie(char **dictionary)
{
	int		i;

	while (dictionary[i])
		i++;
	ft_qsort(dictionary, i, cmp);
}

char *understand(char *word, struct s_trie *trie)
{

}
