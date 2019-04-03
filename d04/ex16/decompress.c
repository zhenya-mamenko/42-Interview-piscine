/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:32:41 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 17:41:38 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int		i, j;
	int		**a;

	if ((a = malloc(sizeof(int *) * bit->n)) == NULL)
		return (NULL);
	i = 0;
	while (i < bit->n)
	{
		if ((a[i] = malloc(sizeof(int) * l)) == NULL)
			return (NULL);
		j = 0;
		while (j < l)
		{
			a[i][j] = ((bit->arr[i] >> j) & 1) ? 1 : 0;
			j++;
		}
		i++;
	}
	return (a);
}
