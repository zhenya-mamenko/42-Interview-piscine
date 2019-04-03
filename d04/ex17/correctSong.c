/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correctSong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:46:14 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 20:58:35 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		pow_int(int p, int base)
{
	int		result;
	result = 1;
	while (p-- > 0)
		result *= base;
	return (result);
}

void correctSong(struct s_bit *bit, int l, int row, int col, int dist)
{
	int i = 0;
	(void)l;

	while (i < dist)
	{
		bit->arr[row + i] |= pow_int(col, 2);
		i++;
	}
}
