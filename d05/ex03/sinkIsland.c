/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sinkIsland.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 17:54:39 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/02 18:02:27 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sinkIsland(int **map, int row, int col)
{
	map[row][col] = 0;
	if (row > 0 && map[row - 1][col] == 1)
		sinkIsland(map, row - 1, col);
	if (map[row + 1] != NULL && map[row + 1][col] == 1)
		sinkIsland(map, row + 1, col);
	if (col > 0 && map[row][col - 1] == 1)
		sinkIsland(map, row, col - 1);
	if (map[row][col + 1] == 1)
		sinkIsland(map, row, col + 1);
}
