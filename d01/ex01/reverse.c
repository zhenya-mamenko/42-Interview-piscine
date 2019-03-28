/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 20:16:20 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/26 20:19:56 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	if (lst->next)
		printReverse(lst->next);
	else
	{
		printf("%s", lst->word);
		return ;
	}
	printf(" %s", lst->word);
}
