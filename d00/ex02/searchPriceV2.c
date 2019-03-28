/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:12 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/25 13:03:03 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int searchPrice(struct s_art **arts, int n, char *name)
{
	int		i, c;

	i = n / 2;
	c = strcmp(name, arts[i]->name);
	if (c == 0)
		return (arts[i]->price);
	else if (n == 1)
		return (-1);
	if (c > 0)
		return (searchPrice(arts + i, n - i, name));
	else
		return (searchPrice(arts, n - i, name));
	return (-1);
}
