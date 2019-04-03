/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:39:05 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 13:01:56 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pow_int(int p)
{
	return (1 << p);
}

int getPlace(unsigned int parkingRow, int pos)
{
	return (parkingRow & pow_int(pos) ? 1 : 0);
}
