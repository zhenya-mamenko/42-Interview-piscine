/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 10:46:12 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/25 11:33:16 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		searchPrice(struct s_art **arts, char *name)
{
	int		i;

	i = 0;
	while (arts[i])
	{
		if (strcmp(arts[i]->name, name) == 0)
			return (arts[i]->price);
		i++;
	}
	return (-1);
}
