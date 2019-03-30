/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printYoungest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:55:51 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 21:40:00 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		find_smallest(int *a, int l)
{
	int		i;
	if (l == 1)
		return (a[0]);
	i = find_smallest(a + 1, l - 1);
	return (a[0] < i ? a[0] : i);
}

void	printYoungest(int *ages, int length)
{
	printf("Youngest : %d\n", find_smallest(ages, length));
}
