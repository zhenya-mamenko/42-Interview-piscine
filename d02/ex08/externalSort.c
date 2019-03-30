/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externalSort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:05:18 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 22:58:21 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cmp(int a, int b)
{
	int		c;

	c = a - b;
	return (c);
}

void		ft_qsort(int *a, size_t cnt, int f(int, int))
{
	size_t	med;
	t_hilo	b;
	t_hilo	fl;
	int		tmp;

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

void externalSort(char *scoreFile, char *sortedFile, int ram)
{
	FILE	*f, *f2;
	int		cnt, *b, *b2, files, ichunk, r, i, j, p;
	char	s[256];

	f = openFile(scoreFile, "r");
	cnt = ram / sizeof(int);
	if ((b = malloc(sizeof(int) * cnt)) == NULL)
		return ;
	if ((b2 = malloc(sizeof(int) * cnt)) == NULL)
		return ;
	files = 0;
	while ((r = readBlock(f, b, cnt)) != 0)
	{
		ft_qsort(b, r, cmp);
		files++;
		sprintf(s, "chunk%d_%s", files, sortedFile);
		writeFile(s, b, cnt);
	}
	fclose(f);
	ichunk = cnt / files;
	j = 0;
	f2 = openFile(sortedFile, "w");
	while (j < cnt / ichunk)
	{
		i = 0;
		p = 0;
		while (i < files)
		{
			sprintf(s, "chunk%d_%s", (i+1), sortedFile);
			f = openFile(scoreFile, "r");
			fseek(f, i * ichunk, SEEK_SET);
			r = readBlock(f, b2, ichunk);
			memmove(&b[i * ichunk], b2, r);
			p += r;
			fclose(f);
			i++;
		}
		ft_qsort(b, p, cmp);
		for (int k = 0; k < p; k++)
			fprintf(f2, "%d\n", b[k]);
		j++;
	}
	fclose(f2);
	i = 0;
	while (i < files)
	{
		i++;
		sprintf(s, "chunk%d_%s", i, sortedFile);
		removefile(s, 0, 0);
	}
}
