/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpNephew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:02:08 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 17:17:47 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double punch(int ns, int p, int ne)
{
	double	result = 0;
	double	k = ((double)1 / (double)ns);

	if (ns <= ne || p == 0)
		return (ns <= ne ? 1 : 0);
	while (ns > 0)
	{
		result += k * punch(ns - 1, p - 1, ne);
		ns--;
	}
	return (result);
}

double probaNephewWillLive(int nStairs, int nPunch, int nephewStair)
{
	return (1 - punch(nStairs, nPunch, nephewStair));
}
