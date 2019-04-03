/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:44:58 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:03:48 by emamenko         ###   ########.fr       */
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
