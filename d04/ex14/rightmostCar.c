/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightmostCar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:45:52 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:36:08 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int rightmostCar(unsigned int parkingRow)
{
	int result = 0;

	if (!parkingRow)
		return (-1);
	while (!(parkingRow & 1))
	{
		parkingRow >>= 1;
		result = inc(result);
	}
	return (result);
}