/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:35:47 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/05 18:15:11 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		cmp(char *a, char *b)
{
	return (strcmp(a, b));
}

void sorting_tree(struct s_art **masterpiece, int n, int i)
{
	struct s_art *tmp;

	if (2 * i + 1 < n && cmp(masterpiece[i]->name, masterpiece[2 * i + 1]->name) < 0)
	{
		if (2 * i + 2 < n && cmp(masterpiece[2 * i + 1]->name, masterpiece[2 * i + 2]->name) < 0)
		{
			tmp = masterpiece[i];
			masterpiece[i] = masterpiece[2 * i + 2];
			masterpiece[2 * i + 2] = tmp;
			sorting_tree(masterpiece, n, 2 * i + 2);
		}
		else if (2 * i + 1 < n)
		{
			tmp = masterpiece[i];
			masterpiece[i] = masterpiece[2 * i + 1];
			masterpiece[2 * i + 1] = tmp;
			sorting_tree(masterpiece, n, 2 * i + 1);
		}
	}
	else
	{
		if (2 * i + 2 < n && cmp(masterpiece[i]->name, masterpiece[2 * i + 2]->name) < 0)
		{
			tmp = masterpiece[i];
			masterpiece[i] = masterpiece[2 * i + 2];
			masterpiece[2 * i + 2] = tmp;
			sorting_tree(masterpiece, n, 2 * i + 2);
		}
	}
}

void	heapSort(struct s_art **masterpiece, int n)
{
	struct s_art *tmp;

	for (int i = (n / 2) - 1; i >= 0; i--)
	{
		sorting_tree(masterpiece, n, i);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		tmp = masterpiece[0];
		masterpiece[0] = masterpiece[i];
		masterpiece[i] = tmp;
		sorting_tree(masterpiece, i, 0);
	}
}
