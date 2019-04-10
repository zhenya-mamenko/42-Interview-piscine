/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:32:29 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 14:39:12 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	int		count = 0, n = 0, l, r, j;

	while (hotspots && hotspots[count])
		count++;
	for (int i = 0; i < count; i++)
	{
		int cr = 0;

		r = hotspots[i]->pos + hotspots[i]->radius;
		l = hotspots[i]->pos - hotspots[i]->radius;
		j = 1;
		while (cr < 2 && (i - j >= 0) && (hotspots[i - j]->radius != 0) &&
			hotspots[i - j]->pos + hotspots[i - j]->radius > l)
		{
			cr++;
			j++;
		}
		j = 1;
		while (cr < 2 && i + j < count && (hotspots[i + j]->radius != 0) &&
			hotspots[i + j]->pos - hotspots[i + j]->radius < r)
		{
			cr++;
			j++;
		}
		if (cr > 1)
		{
			hotspots[i]->radius = 0;
			n++;
		}
	}
	for (int i = 1; i < count; i++)
		if (hotspots[i - 1]->radius != 0 && (hotspots[i]->pos - hotspots[i]->radius <
			hotspots[i - 1]->pos + hotspots[i - 1]->radius))
	{
		hotspots[i]->radius = 0;
		n++;
	}
	return (count - n);
}
