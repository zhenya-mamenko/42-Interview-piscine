/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:29:54 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:33:23 by emamenko         ###   ########.fr       */
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

int carPosition(unsigned int parkingRow)
{
	unsigned int result = 0;
	if (!parkingRow)
		return (-1);
	while (parkingRow && !(parkingRow & 1))
	{
		parkingRow >>= 1;
		result = inc(result);
	}
	if (parkingRow & ~0x00000001)
		return (-1);
	return (result);
}
