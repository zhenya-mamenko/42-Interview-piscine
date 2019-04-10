/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:33:15 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/05 23:35:53 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_sellers *closestSellers(struct s_graph *parisPlaces, char *youAreHere)
{
	struct s_queue		*q = queueInit();
	struct s_node		*n;
	struct s_sellers	*s;
	int					i, cnt, d, k, j;

	s = malloc(sizeof(struct s_sellers));
	cnt = 0;
	n = NULL;
	while (parisPlaces->places[cnt])
	{
		if (strcmp(parisPlaces->places[cnt]->name, youAreHere) == 0)
			n = parisPlaces->places[cnt];
		cnt++;
	}
	if (n == NULL)
		return (NULL);
	n->visited = 0;
	s->placeNames = malloc(sizeof(char *) * cnt);
	enqueue(q, n);
	i = 0;
	d = -1;
	k = 0;
	while (i < cnt)
	{
		n = dequeue(q);
		if (n == NULL)
			break ;
		if (d > 0 && n->visited > d)
			break ;
		if (n->hasCerealBar == 1)
		{
			s->distance = n->visited;
			s->placeNames[k++] = n->name;
			d = n->visited;
		}
		else
		{
			j = 0;
			while (n->connectedPlaces[j])
			{
				if (n->connectedPlaces[j]->visited == 0)
				{
					n->connectedPlaces[j]->visited = n->visited + 1;
					enqueue(q, n->connectedPlaces[j]);
				}
				j++;
			}
		}
		n->visited = 1000;
		i++;
	}
	s->placeNames[k] = NULL;
	return (s);
}
