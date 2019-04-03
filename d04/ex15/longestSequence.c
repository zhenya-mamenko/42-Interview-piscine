/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longestSequence.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:53:52 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:50:43 by emamenko         ###   ########.fr       */
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

int longestSequence(unsigned int parkingRow)
{
	int count = 0;

	while (parkingRow)
	{
		parkingRow = (parkingRow & (parkingRow << 1));
		count = inc(count);
	}
	return (count);
}
