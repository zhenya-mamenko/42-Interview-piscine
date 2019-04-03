/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isFilled.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:50:12 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 13:05:52 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int isFilled(unsigned int parkingRow)
{
	if ((parkingRow & 1) == 0)
			return (0);
	parkingRow >>= 1;
	if (parkingRow == 0)
		return (1);
	else
		return (isFilled(parkingRow));
}
