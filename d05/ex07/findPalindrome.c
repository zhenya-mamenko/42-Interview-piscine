/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPalindrome.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:09:07 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/03 23:03:10 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check(char *s)
{
	int		l = 0, r = strlen(s) - 1;

	for (int i = 0; i < (int)strlen(s) && l <= r; i++) {
		while ((s[l] == ' ' && l++) || (s[r] == ' ' && r--))
			;
		if (s[l++] != s[r--])
			return (0);
	}
	return (1);
}

char	*pal(char *s, int n)
{
	char	c, *tmp = NULL;

	if (n == 0)
		return (check(s) == 1 ? s : NULL);
	for (int i = 0; i < (int)strlen(s); i++)
		if ((c = s[i]) != ' ') {
			s[i] = ' ';
			if ((tmp = pal(s, n - 1)) != NULL)
				return (tmp);
			s[i] = c;
		}
	return (tmp);
}

char	*findPalindrome(char *sequence, int nDelete)
{
	char	*s = pal(strdup(sequence), nDelete);
	char	*buf = malloc(strlen(sequence) - nDelete + 1);

	while (s && *s)
		if (*s++ != ' ')
			*buf++ = *(s - 1);
	*buf = '\0';
	return (s == NULL ? NULL : buf - strlen(sequence) + nDelete);
}
