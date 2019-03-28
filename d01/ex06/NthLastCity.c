/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:02:23 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/27 18:21:40 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define ALLOC	1000

int		put_city(char ***a, char *city, int *count)
{
	char	**b;
	int		c;

	c = *count;
	if (c % ALLOC == 0)
	{
		if ((b = malloc(sizeof(char *) * (c + ALLOC))) == NULL)
			return (0);
		if (c != 0)
		{
			memmove(b, *a, sizeof(char *) * (c));
			free(a);
		}
		*a = b;
	}
	b = *a;
	b[c] = city;
	*count += 1;
	return (1);
}

char	*NthLastCity(struct s_city *city, int n)
{
	int		count;
	char	**a;

	a = NULL;
	count = 0;
	while (city)
	{
		put_city(&a, city->name, &count);
		city = city->next;
	}
	return (a[count - n - 1]);
}
