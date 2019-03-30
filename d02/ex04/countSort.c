/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:49:44 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 14:53:19 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void countSort(unsigned char *utensils, int n)
{
	int		a[NUMBER_OF_USTENSILS]; // U can set max of uchar + 1 = 256
	int		i, c;

	memset(a, 0, NUMBER_OF_USTENSILS * sizeof(int));
	i = 0;
	while (i < n)
		a[utensils[i++]]++;
	i = 0;
	c = 0;
	while (i <= NUMBER_OF_USTENSILS)
	{
		if (a[i] != 0)
		{
			memset(utensils + c, (unsigned char)i, a[i]);
			c += a[i];
		}
		i++;
	}
}
