/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPriceV2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:43:56 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/03 16:47:52 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	psplit(int size, double *prices, double *max)
{
	double	price;

	if (size == 0 || max[size] > 0)
		return (max[size]);
	if (size == 1)
		return (max[1]);
	max[size] = prices[size];
	for (int i = 1; i < size; i++) {
		price = max[i] + psplit(size - i, prices, max);
		if (price > max[size])
			max[size] = price;
	}
	return (max[size]);
}

double	optimizedBestPrice(int pizzaSize, double *prices)
{
	double	max[pizzaSize + 1];

	for (int i = 0; i <= pizzaSize; i++)
		max[i] = 0;
	max[1] = prices[1];
	return (psplit(pizzaSize, prices, max));
}

