/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:46:31 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/04 11:06:47 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	calc(double d, double w, int n)
{
	double	result = 0;

	if (n == 0 || d >= w || d == 0)
		return (d >= w ? 1 : 0);
	result += 0.4864864865 * calc(d * 2, w, n - 1);
	result += 0.4864864865 * calc(d * 0, w, n - 1);
	result += 0.02702702703 * calc(d / 2, w, n - 1);
	return (result);
}

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
	return (calc(firstDollarsBet, dollarsWanted, nbGame));
}
