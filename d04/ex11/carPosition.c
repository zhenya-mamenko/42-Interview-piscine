/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carPosition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:29:54 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 16:41:28 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int carPosition(unsigned int parkingRow)
{
	int result = 0;
	if (parkingRow == 0)
		return (-1);
	while (parkingRow && (parkingRow % 2 == 0))
	{
		parkingRow /= 2;
		result++;
	}
	if (parkingRow / 2 != 0)
		return (-1);
	return (result);
}
