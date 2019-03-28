/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 22:53:45 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/26 21:19:27 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*b;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (strdup(""));
		else
			return ((char *)(s1 == NULL ? strdup(s2) : strdup(s1)));
	}
	l1 = strlen(s1);
	l2 = strlen(s2);
	b = malloc(sizeof(char) * (l1 + l2 + 1));
	if (b != NULL)
	{
		strcpy(b, s1);
		strcpy(b + l1, s2);
		b[l1 + l2] = '\0';
	}
	return (b);
}

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
		hash = (hash + int_pow(101, l - i - 1) * s[i]) & 0xfffffffffffffff;
		i++;
	}
	return (hash);
}

size_t	hash(char *input)
{
	return (make_hash(input, strlen(input)));
}

struct s_dict	*dictInit(int capacity)
{
	struct s_dict	*result;
	int				i;

	result = malloc(sizeof(struct s_dict));
	result->capacity = capacity;
	result->items = malloc(sizeof(struct s_item *) * capacity);
	i = 0;
	while (i < capacity)
	{
		result->items[i] = NULL;
		i++;
	}
	return (result);
}

int				dictInsert(struct s_dict *dict, char *key, int value)
{
	size_t	h;
	struct s_item	*item;

	h = hash(key) % (dict->capacity);
	if ((item = dict->items[h]) != NULL)
	{
		while (item->next)
			item = item->next;
		item->next = malloc(sizeof(struct s_item));
		item = item->next;
	}
	else
	{
		dict->items[h] = malloc(sizeof(struct s_item));
		item = dict->items[h];
	}

	item->value = value;
	item->key = strdup(key);
	item->next = NULL;
	return (0);
}

int				dictSearch(struct s_dict *dict, char *key)
{
	size_t	h;
	struct s_item	*item;

	h = hash(key) % (dict->capacity);
	item = dict->items[h];
	while (item)
		if (strcmp(item->key, key) == 0)
			break ;
		else
			item = item->next;
	return (item != NULL ? item->value : -1);
}

struct s_item	*dictItemV(struct s_dict *dict, int value)
{
	int		i;
	struct s_item	*item;

	i = 0;
	while (i < dict->capacity)
	{
		item = dict->items[i];
		while (item)
		{
			if (item->value == value)
				return (item);
			item = item->next;
		}
		i++;
	}
	return (NULL);
}

struct s_item	*dictItemH(struct s_dict *dict, size_t hh)
{
	size_t	h;
	struct s_item	*item;

	h = hh % (dict->capacity);
	item = dict->items[h];
	return (item);
}

char			*compress(char *book, struct s_dict *dict)
{
	size_t	i, j, k, h, h2, l, l2, max_l;
	int		r;
	struct s_item	*item;
	char	*s;

	l = 1000;
	max_l = 0;
	i = -1;
	k = 0;
	while (++i < (size_t)dict->capacity)
	{
		if (dict->items[i] == NULL)
			continue ;
		l2 = strlen(dict->items[i]->key);
		k += l2;
		if (l2 < l)
			l = l2;
		if (l2 > max_l)
			max_l = l2;
	}
	s = malloc(strlen(book) + (dict->capacity + 1) + k);
	sprintf(s, "%s", "<");
	k = 1;
	i = 0;
	while (++i <= (size_t)dict->capacity)
	{
		item = dictItemV(dict, i);
		sprintf(s + k, "%s,", item->key);
		k += strlen(item->key) + 1;
		item = item->next;
	}
	sprintf(s + k - 1, "%s", ">");
	l2 = strlen(book) - l + 1;
	h = make_hash(book, l);
	i = 0;
	while (i < l2)
	{
		j = l;
		h2 = h;
		s[k] = book[i];
		while ((j <= max_l) && (i + j < l2 + l))
		{
			if ((item = dictItemH(dict, h2)) != NULL)
			{
				while (item)
					if (strncmp(item->key, &book[i], j) == 0)
						break ;
					else
						item = item->next;
				if (item != NULL)
				{
					r = item->value;
					s[k++] = '@';
					s[k] = (char)r;
					i += (j - 1);
					h = make_hash(&book[i], l);
					break ;
				}
			}
			j++;
			h2 = (h2 * 101) & 0xfffffffffffffff;
			h2 = (h2 + book[i + j - 1]) & 0xfffffffffffffff;
		}
		i++;
		k++;
		h = (h - int_pow(101, l - 1) * book[i - 1]) & 0xfffffffffffffff;
		h = (h * 101) & 0xfffffffffffffff;
		h = (h + book[i + l - 1]) & 0xfffffffffffffff;
	}
	while (i < l2 + l)
		s[k++] = book[i++];
	s[k] = 0;
	return (s);
}
