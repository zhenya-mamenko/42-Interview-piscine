/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 21:22:22 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/26 21:43:28 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void rotate(int **picture, int n)
{
	int		i, j, tmp;

	i = 0;
	while (i < n /2)
	{
		j = i;
		while (j < n - i - 1)
		{
			tmp = picture[i][j];
			picture[i][j] = picture[n - j - 1][i];
			picture[n - j - 1][i] = picture[n - i - 1][n - j - 1];
			picture[n - i - 1][n - j - 1] = picture[j][n - i - 1];
			picture[j][n - i - 1] = tmp;
			j++;
		}
		i++;
	}
}
