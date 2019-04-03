/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   occupiedPlaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:16:36 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:47:06 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int inc(unsigned int v)
{
	unsigned int mask = 1;
	while (v & mask)
	{
		v &= ~mask;
		mask <<= 1;
	}
	v |= mask;
	return (v);
}

int dec(int v)
{
	return ((v << 1) + (~v));
}

int occupiedPlaces(unsigned int parkingRow)
{
	int result = 0;
	while (parkingRow)
	{
		result = inc(result);
		parkingRow = parkingRow & (dec(parkingRow));
	}
	return (result);
}
