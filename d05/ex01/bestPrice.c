/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:52:23 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 16:16:42 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	psplit(int size, double *prices, int sum, double price, double *max)
{
	for (int i = size; i > 0; i--) {
		sum += i;
		price += prices[i];
		if (sum <= size) {
			if (sum == size) {
				if (price > *max)
					*max = price;
			}
			else
				psplit(size, prices, sum, price, max);
		}
		price -= prices[i];
		sum -= i;
	}
}

double	bestPrice(int pizzaSize, double *prices)
{
	double	result = 0;

	psplit(pizzaSize, prices, 0, 0, &result);
	return (result);
}
