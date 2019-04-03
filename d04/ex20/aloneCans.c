/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:39:50 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 20:47:05 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void aloneCans(int *arr, int n)
{
	int x = 0, a = 0, b = 0, i;

	i = 0;
	while (i < n)
	{
		x ^= arr[i];
		i++;
	}
	int rightmost = x & ~(x - 1);
	i = 0;
	while (i < n)
	{
		if (arr[i] & rightmost)
			a = a ^ arr[i];
		else
			b = b ^ arr[i];
		i++;
	}

	printf("%d\n%d\n", a, b);
}
