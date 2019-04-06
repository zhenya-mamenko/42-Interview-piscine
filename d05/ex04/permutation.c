/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 18:05:10 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 20:46:02 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		len(char *s)
{
	int		l = 0;

	while (s[l])
		l++;
	return (l);
}

char	*shift(char *s)
{
	char	*r = strdup(s);
	char	c = s[0];

	memmove(r, r + 1, len(r) - 1);
	r[len(r) - 1] = c;
	return (r);
}

void permutation(char *str, char *p, int size)
{
	char	*s = str;

	for (int i = 0; i < len(str); i++) {
		p[size - len(s)] = s[0];
		p[size - len(s) + 1] = '\0';
		permutation(s + 1, p, size);
		s = shift(s);
	}
	if (len(str) == 0)
		printf("%s\n", p);
}

void	printPermutations(char *str)
{
	permutation(str, malloc(len(str) + 1), len(str));
}
