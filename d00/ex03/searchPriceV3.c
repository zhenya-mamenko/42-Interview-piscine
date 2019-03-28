/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:12 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/25 19:43:34 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t			hash(char *input)
{
	size_t	i, j, result, h;

	i = 0;
	result = 0;
	while (i < 4)
	{
		h = T[(input[0] + i) % 256];
		j = 0;
		while (j < strlen(input))
		{
			h = T[h ^ input[i]];
			j++;
		}
		result = (result << 8) + (h & 0xff);
		i++;
	}
	return (result);
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

int				dictInsert(struct s_dict *dict, char *key, struct s_art *value)
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

struct s_art	*dictSearch(struct s_dict *dict, char *key)
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
	return (item != NULL ? item->value : NULL);
}

int		searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*a;

	a = dictSearch(dict, name);
	if (a != NULL)
		return (a->price);
	else
		return (-1);
}
