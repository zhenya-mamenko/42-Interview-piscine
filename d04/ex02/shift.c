/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 10:12:50 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/03 16:18:57 by emamenko         ###   ########.fr       */
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

int toInt(char *bits)
{
	int result = 0, i = 0;

	while (i < (int)strlen(bits))
	{
		result += pow_int(strlen(bits) - i - 1, 2) * (bits[i] - '0');
		i++;
	}
	if (bits[0] == '1')
		result -= pow_int(strlen(bits), 2);
	return (result);
}

char *rightShift(char *bin, int k)
{
	int i = k;
	char c = bin[0];

	while (i < (int)strlen(bin))
	{
		bin[i] = bin[i - k];
		i++;
	}
	i = 0;
	while (i < k)
	{
		bin[i] = c;
		i++;
	}
	return (bin);
}


char *leftShift(char *bin, int k)
{
	int i = k;
	while (i < (int)strlen(bin))
	{
		bin[i - k] = bin[i];
		i++;
	}
	i = 0;
	while (i < k)
	{
		bin[strlen(bin) - i - 1] = '0';
		i++;
	}
	return (bin);
}
