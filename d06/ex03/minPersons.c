/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minPersons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:08:52 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 15:23:51 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		minPersons(int elements, int minPercentage)
{
	double	value = 1.0;
	int		n = 1;

	while (n <= elements && 1 - value <= (double)minPercentage / 100)
	{
		value *= (double)(elements - n) / elements;
		n++;
	}
	return (n);
}
