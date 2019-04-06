/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:11:39 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 16:10:57 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	split(int size, struct s_array *a)
{
	for (int i = size; i > 0; i--) {
		struct s_array *b = arrayClone(a);
		arrayAppend(b, i);
		if (b->sum <= size) {
			if (b->sum == size)
				arrayPrint(b);
			else
				split(size, b);
		}
		free(b);
	}
}

void	printPossibleSlices(int pizzaSize)
{
	struct s_array	*a;

	a = arrayInit();
	split(pizzaSize, a);
	free(a);
}
