/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 17:06:44 by emamenko          #+#    #+#             */
/*   Updated: 2019/03/28 19:24:11 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		binary_search(int *rocks, int n, int value)
{
	int		i, c;

	i = n / 2;
	c = value - rocks[i];
	if (c == 0)
		return (i);
	else if (n == 1)
		return (-1);
	if (c > 0)
	{
		c = binary_search(rocks + i, n - i, value);
		c = c == -1 ? -1 : c + i;
		return (c);
	}
	else
	{
		c = binary_search(rocks, i, value);
		return (c);
	}
	return (-1);
}

int		first_index(int *rocks, int index)
{
	int		value;

	if (index <= 0)
		return (index);
	value = rocks[index];
	if (rocks[0] == value)
		return (0);
	while (rocks[index] == value && index >= 0)
		index--;
	return (index + 1);
}

int		find_pivot(int *rocks, int n)
{
	int		i;

	i = 1;
	while (i < n)
	{
		if (rocks[i - 1] > rocks[i])
			break;
		i++;
	}
	return (i == n ? 0 : i);
}

int		searchShifted(int *rocks, int length, int value)
{
	int		pivot, c;

	if (length == 0)
		return (-1);
	if (length == 1)
		return (rocks[0] == value ? 0 : -1);
	if ((pivot = find_pivot(rocks, length)) == 0)
		return (first_index(rocks, binary_search(rocks, length, value)));
	if (rocks[pivot] == value)
		return (first_index(rocks, pivot));
	else if (rocks[0] < value)
		return (first_index(rocks, binary_search(rocks, pivot, value)));
	else
	{
		c = binary_search(rocks + pivot, length - pivot, value);
		c = c == -1 ? -1 : c + pivot;
		return (first_index(rocks, c));
	}
}
