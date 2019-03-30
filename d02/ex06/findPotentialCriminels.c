/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findPotentialCriminels.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:33:18 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 20:35:15 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue	*q;

	if ((q = malloc(sizeof(struct s_queue))) == NULL)
		return (NULL);
	q->first = q->last = NULL;
	return (q);
}

int isEmpty(struct s_queue *queue)
{
	return (queue->first ? 0 : 1);
}

struct s_criminal	*dequeue(struct s_queue *queue)
{
	struct s_node	*n;
	struct s_criminal	*cr;

	n = queue->first;
	if (!n)
		return (NULL);
	queue->first = n->next;
	cr = n->cr;
	free(n);
	return (cr);
}

void enqueue(struct s_queue *queue, struct s_criminal *cr)
{
	struct s_node	*n;

	if ((n = malloc(sizeof(struct s_node))) == NULL)
		return ;
	n->cr = cr;
	n->next = NULL;
	if (isEmpty(queue))
	{
		queue->first = queue->last = n;
	}
	else
	{
		queue->last->next = n;
		queue->last = n;
	}
}

int		pow10(int p)
{
	int		result;
	result = 1;
	while (p-- > 0)
		result *= 10;
	return (result);
}

int getDescription(struct s_info *info)
{
	int		description;

	description = info->gender * pow10(6)
		+ info->height * pow10(5)
		+ info->hairColor * pow10(4)
		+ info->eyeColor * pow10(3)
		+ info->glasses * pow10(2)
		+ info->tattoo * 10
		+ info->piercing;
	return (description);
}

void sortCriminals(struct s_criminal **criminals)
{
	struct s_queue *b[10];
	int		i, j, n;

	i = 0;
	while (i < 10)
	{
		b[i] = queueInit();
		i++;
	}
	i = 0;
	while (i < 7)
	{
		j = 0;
		while (criminals[j])
		{
			n = (criminals[j]->description / pow10(i)) % 10;
			enqueue(b[n], criminals[j]);
			j++;
		}
		j = 0;
		n = 0;
		while (n < 10)
		{
			while (!isEmpty(b[n]))
				criminals[j++] = dequeue(b[n]);
			n++;
		}
		i++;
	}
}

int		binary_search(struct s_criminal **criminals, int n, int value)
{
	int		i, c;

	i = n / 2;
	c = value - criminals[i]->description;
	if (c == 0)
		return (i);
	else if (n == 1)
		return (-1);
	if (c > 0)
	{
		c = binary_search(criminals + i, n - i, value);
		c = c == -1 ? -1 : c + i;
		return (c);
	}
	else
	{
		c = binary_search(criminals, i, value);
		return (c);
	}
	return (-1);
}

int		first_index(struct s_criminal **criminals, int index)
{
	int		value;

	if (index <= 0)
		return (index);
	value = criminals[index]->description;
	while (criminals[index]->description == value && index >= 0)
		index--;
	return (index + 1);
}


struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
{
	int		index, l, d;
	struct s_criminal	**found;

	l = 0;
	while (criminals[l])
		l++;
	d = getDescription(info);
	index = first_index(criminals, binary_search(criminals, l, d));
	if (index == -1)
		return (NULL);
	l = 0;
	while (criminals[index + l]->description == d)
		l++;
	if ((found = malloc(sizeof(struct s_criminal *) * (l + 1))) == NULL)
		return (NULL);
	d = 0;
	while (d < l)
	{
		found[d] = criminals[index + d];
		d++;
	}
	found[d] = NULL;
	return (found);
}
