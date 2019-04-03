/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aloneCan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:35:09 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 18:38:26 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void aloneCan(int *arr, int n)
{
	int result = 0, i = 0;

	while (i < n)
	{
		result ^= arr[i];
		i++;
	}
	printf("%d\n", result);
}
