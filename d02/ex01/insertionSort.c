/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 09:36:58 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 10:20:36 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	insert_value(struct s_player **players, int i)
{
	struct s_player	*p;
	int				j;

	p = players[i];
	j = 0;
	while (j < i)
	{
		if (players[j]->score < p->score)
		{
			memmove(&players[j + 1], &players[j], sizeof(struct s_player *) * (i - j));
			players[j] = p;
			break ;
		}
		j++;
	}
}

void	insertionSort(struct s_player **players)
{
	int				last, i, max, f;

	if (!*players)
		return ;
	last = 0;
	max = players[0]->score;
	f = 1;
	while (players[last] && f == 1)
	{
		f = 0;
		i = last + 1;
		while (players[i])
		{
			if (players[i]->score > max)
			{
				f = 1;
				insert_value(players, i);
			}
			else
			{
				max = players[i]->score;
				last = i;
			}
			i++;
		}
		last++;
	}
}
