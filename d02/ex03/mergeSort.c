/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:51:11 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 13:31:46 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sort(struct s_player **players, struct s_player **buf, int l, int r)
{
	int		mid, li, ri, i;

	if (l == r)
	{
		return ;
	}
	mid = (l + r) / 2;
	sort(players, buf, l, mid);
	sort(players, buf, mid + 1, r);
	li = l, ri = mid + 1;
	i = l;
	while (i <= r)
	{
		if (li <= mid && ri <= r)
		{
			if (players[li]->score < players[ri]->score)
				buf[i] = players[ri++];
			else
				buf[i] = players[li++];
		}
		else if (li <= mid)
		{
			buf[i] = players[li];
			li++;
		}
		else
		{
			buf[i] = players[ri];
			ri++;
		}
		i++;
	}
	memmove(&players[l], &buf[l], sizeof(struct s_player *) * (r - l + 1));
}

struct s_player **mergeSort(struct s_player **players)
{
	int		i;
	struct s_player	**buf;

	i = 0;
	while (players[i])
		i++;
	if ((buf = malloc(sizeof(struct s_player *) * (i + 1))) == NULL)
		return (NULL);
	buf[i] = NULL;
	sort(players, buf, 0, i - 1);
	free(buf);
	return (players);
}
