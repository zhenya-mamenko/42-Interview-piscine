/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeThemEat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:59:07 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/03 17:39:43 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find(struct s_people **people, int *tables, int p, int t_cnt)
{
	if (people[p] == NULL)
		return (1);
	for (int i = 0; i < t_cnt; i++) {
		if (tables[i] >= people[p]->time) {
			tables[i] -= people[p]->time;
			if (find(people, tables, p + 1, t_cnt) == 1)
				return (1);
			tables[i] += people[p]->time;
		}
	}
	return (0);
}

int		isPossible(struct s_people **people, int nbTable, int totalTime)
{
	int		tables[nbTable];

	for (int i = 0; i < nbTable; i++)
		tables[i] = totalTime;
	return (find(people, tables, 0, nbTable));
}
