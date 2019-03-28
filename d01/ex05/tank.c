/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 14:36:19 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 16:47:00 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_tank *initTank(void)
{
	struct s_stack	**s;
	struct s_tank	*t;

	if ((t = malloc(sizeof(struct s_tank))) == NULL)
		return (NULL);
	t->n = 1;
	if ((s = malloc(sizeof(struct s_stack *) * t->n)) == NULL)
		return (NULL);
	t->stacks = s;
	if ((*s = malloc(sizeof(struct s_stack))) == NULL)
		return (NULL);
	(*s)->elem = NULL;
	(*s)->sum = 0;
	return (t);
}

void tankPush(struct s_tank *tank, int energy)
{
	struct s_stack	**s;
	struct s_elem	*e;

	if (tank->stacks[tank->n - 1]->sum + energy > 1000)
	{
		if ((s = malloc(sizeof(struct s_stack *) * (tank->n + 1))) == NULL)
			return ;
		memmove(s, tank->stacks, sizeof(struct s_stack *) * (tank->n));
		tank->stacks = s;
		if ((tank->stacks[tank->n] = malloc(sizeof(struct s_stack))) == NULL)
			return ;
		tank->stacks[tank->n]->elem = NULL;
		tank->stacks[tank->n]->sum = 0;
		tank->n += 1;
	}
	if ((e = malloc(sizeof(struct s_elem))) == NULL)
		return ;
	e->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = e;
	e->energy = energy;
	tank->stacks[tank->n - 1]->sum += energy;
	printf("push(%d)\n", energy);
}

int tankPop(struct s_tank *tank)
{
	int		result;
	struct s_stack	*s;
	struct s_elem 	*e;

	s = tank->stacks[tank->n - 1];
	e = s->elem;
	if (e == NULL)
		return (0);
	result = e->energy;
	s->sum -= result;
	s->elem = s->elem->next;
	free(e);
	if (s->sum == 0 && tank->n > 1)
	{
		free(s);
		tank->n -= 1;
	}
	printf("pop()\n");
	return (result);
}
