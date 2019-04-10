/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 09:59:41 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 10:26:48 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check(int pos, int dist, int *locations, int n)
{
	int		count = 0;

	for (int i = 0; i < n; i++)
	{
		count += (locations[i] - pos > dist) ? 1 : 0;
	}
	return (count);
}

double	probaDistance(int dist, int *locations, int n)
{
	int		count = 0, n_count = 0;

	for (int i = 1; i < n; i++)
	{
		count += check(locations[i - 1], dist, locations + i, n - i);
		n_count += (n - i);
	}
	return ((double)count / (double)n_count);
}
