/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:32:24 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 12:35:07 by emamenko         ###   ########.fr       */
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

	return (result);
}

char *getNot(char *a)
{
	int i = 0;
	while (i < (int)strlen(a))
	{
		a[i] = a[i] == '0' ? '1' : '0';
		i++;
	}
	return (a);
}

char *getXor(char *a, char *b)
{
	if (a[0] == '~')
	{
		a++;
		a = getNot(a);
	}
	if (b[0] == '~')
	{
		b++;
		b = getNot(b);
	}
	int i = 0;
	while (i < (int)strlen(a))
	{
		a[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
		i++;
	}
	return (a);
}
