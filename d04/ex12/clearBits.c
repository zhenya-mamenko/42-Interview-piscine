/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearBits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:43:22 by emamenko          #+#    #+#             */
/*   Updated: 2019/04/01 16:44:35 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int clearBits(unsigned int parkingRow, int n)
{
	return (parkingRow & (0xffffffff << n));
}