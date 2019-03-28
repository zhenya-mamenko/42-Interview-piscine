/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:56:36 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/27 17:34:10 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_string *stringInit(void)
{
	struct s_string	*s;

	s = malloc(sizeof(struct s_string));
	if (s != NULL)
	{
		s->content = NULL;
		s->length = 0;
		s->capacity = 0;
	}
	return (s);
}

int	stringAppend(struct s_string *s, char *add)
{
	size_t	f, ls, la;
	char	*ss;

	ls = s->length;
	la = add ? strlen(add) : 0;
	f = 0;
	while ((int)(ls + la + 1) > (s->capacity))
	{
		s->capacity += ASIZE;
		f = 1;
	}
	if (f == 1)
	{
		ss = malloc(s->capacity);
		if (ss == NULL)
			return (0);
		if (ls != 0)
			strcpy(ss, s->content);
		free(s->content);
		s->content = ss;
	}
	strcpy(s->content + ls, add);
	s->length = ls + la;
	(s->content)[s->length] = 0;
	return (1);
}

char *decompress(char *cBook)
{
	struct s_string *s;
	int		i, b, c, j;
	char	*a[255], ch, *ss;

	i = 1;
	b = 1;
	c = 1;
	while (cBook[i] != '>')
	{
		if (cBook[i] == ',')
		{
			a[c] = malloc(i - b + 1);
			strncpy(a[c], cBook + b, i - b);
			a[c++][i - b + 1] = '\0';
			b = i + 1;
		}
		i++;
	}
	a[c] = malloc(i - b + 1);
	strncpy(a[c], cBook + b, i - b);
	a[c][i - b + 1] = '\0';
	s = stringInit();
	b = i + 1;
	while ((ch = cBook[++i]))
	{
		if (ch == '@')
		{
			ss = strndup(cBook + b, i - b);
			if (stringAppend(s, ss) != 1)
			{
				printf("error on append - %s!\n", ss);
				return (NULL);
			}
			free(ss);
			j = (unsigned char)cBook[++i];
			ss = a[j];
			if (stringAppend(s, ss) != 1)
			{
				printf("error on append - %s!\n", ss);
				return (NULL);
			}
			b = i + 1;
		}
	}
	stringAppend(s, cBook + b);
	return (s->content);
}
