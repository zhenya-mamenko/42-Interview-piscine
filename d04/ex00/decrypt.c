/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 09:49:56 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 09:59:46 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pow_int(int p, int base)
{
	int		result;
	result = 1;
	while (p-- > 0)
		result *= base;
	return (result);
}

char *getSum(char *a, char *b)
{
	int i = 5, sticky = 0;

	while (i >= 0)
	{
		int s = (a[i] - '0') + (b[i] - '0') + sticky;
		if (s >= 2)
		{
			s = s % 2;
			sticky = 1;
		}
		else
			sticky = 0;
		a[i] = s + '0';
		i--;
	}
	return (a);
}

int toInt(char *bits)
{
	int result = 0, i = 0;

	while (i < (int)strlen(bits))
	{
		result += pow_int(strlen(bits) - i - 1, 2) * (bits[i] - '0');
		i++;
	}

	return (result);
}
