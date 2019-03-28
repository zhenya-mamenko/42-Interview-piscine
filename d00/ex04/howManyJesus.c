/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 20:01:15 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/25 22:47:20 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	int_pow(size_t b, size_t e)
{
	size_t	result;

	result = 1;
	while (e-- > 0)
		result = (result * b) & 0xFFFFFFFFFFFFFFFUL;
	return (result);
}

size_t	make_hash(char *s, size_t l)
{
	size_t	i, hash;

	i = 0;
	hash = 0;
	while (i < l)
	{
		hash += int_pow(101, l - i - 1) * s[i];
		i++;
	}
	return (hash);
}

int 	howManyJesus(char *bible, char *jesus)
{
	size_t	i, hash, hash2, l, l2, count;

	l = strlen(jesus);
	hash = make_hash(jesus, l);
	hash2 = make_hash(bible, l);
	l2 = strlen(bible) - l + 1;
	i = 0;
	count = 0;
	while (i < l2)
	{
		if (hash == hash2 && strncmp(jesus, &bible[i], l) == 0)
			count++;
		hash2 -= int_pow(101, l - 1) * bible[i];
		hash2 *= 101;
		hash2 += bible[i + l];
		i++;
	}
	return (count);
}
