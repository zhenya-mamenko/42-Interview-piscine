/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printMST.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:32:00 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 18:48:31 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check(struct s_node	**t, struct s_node	*n)
{
	int		i = 0;

	while (t[i])
	{
		if (n == t[i])
			return (1);
		i++;
	}
	return (0);
}

void	printMST(struct s_graph *graph)
{
	struct s_node	*n, *n1, *next, **t;
	int				d, i, cnt, k, j;

	cnt = 0;
	while (graph->nodes[cnt])
		cnt++;
	if (cnt == 0)
		return ;
	t = malloc(sizeof(struct s_node *) * cnt);
	memset(t, 0, sizeof(struct s_node *) * cnt);
	t[0] = graph->nodes[0];
	k = 1;
	while (k < cnt)
	{
		d = INT32_MAX;
		j = 0;
		while (t[j])
		{
			n = t[j];
			i = 0;
			while (n->edges[i])
			{
				if (n->edges[i]->dist < d && check(t, n->edges[i]->dest) == 0)
				{
					d = n->edges[i]->dist;
					next = n->edges[i]->dest;
					n1 = t[j];
				}
				i++;
			}
			j++;
		}
		printf("%8d : %s - %s\n", d, n1->name, next->name);
		t[k] = next;
		k++;
	}
}
