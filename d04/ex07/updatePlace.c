/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updatePlace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:47:53 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:04:56 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pow_int(int p)
{
	return (1 << p);
}

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow | (pow_int(pos)));
}

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow & (~pow_int(pos)));
}

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	return (value == 1 ? setPlace(parkingRow, pos) : clearPlace(parkingRow, pos));
}