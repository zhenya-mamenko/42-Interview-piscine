/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:12 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/25 17:39:13 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cmp(struct s_art *a, struct s_art *b)
{
	int				c;

	c = strcmp(a->name, b->name);
	return (c);
}

void		ft_qsort(struct s_art **a, size_t cnt,
	int f(struct s_art *, struct s_art *))
{
	size_t	med;
	t_hilo	b;
	t_hilo	fl;
	struct s_art *tmp;

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


void	sortArts(struct s_art **arts)
{
	int		len;

	len = 0;
	while (arts[len])
		len++;
	ft_qsort(arts, len, cmp);
}
