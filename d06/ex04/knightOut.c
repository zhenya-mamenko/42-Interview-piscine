/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knightOut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:18:46 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 15:56:44 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		getInitialPos(uint64_t board)
{
	int		pos = 0;

	if (board == 0)
		return (-1);
	while (board)
	{
		if ((board & 1) == 0)
			board >>= 1;
		else
			return ((board & ~1ULL) == 0 ? pos : -1);
		pos++;
	}
	return (pos);
}

double	move(int row, int col, int n)
{
	double	p = 0;

	if (n == 0 || row < 0 || row > 7 || col < 0 || col > 7)
		return ((row < 0 || row > 7 || col < 0 || col > 7) ? 1 : 0);

	p += 0.125 * move(row - 2, col + 1, n - 1);
	p += 0.125 * move(row - 1, col + 2, n - 1);
	p += 0.125 * move(row + 1, col + 2, n - 1);
	p += 0.125 * move(row + 2, col + 1, n - 1);
	p += 0.125 * move(row + 2, col - 1, n - 1);
	p += 0.125 * move(row + 1, col - 2, n - 1);
	p += 0.125 * move(row - 1, col - 2, n - 1);
	p += 0.125 * move(row - 2, col - 1, n - 1);

	return (p);
}

double	knightOut(uint64_t board, int n)
{
	int		pos;

	if ((pos = getInitialPos(board)) == -1 || n < 1)
		return (-1);
	return (move(pos / 8, pos % 8, n));
}
