/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:19 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/10 13:13:33 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_last_3_a1(t_Intarr *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2])
	{
		rrx(a);
		write(1, "rra\n", 4);
		return (1);
	}
	if (a->arr[0] > a->arr[1] && a->arr[0] < a->arr[2])
	{
		sa(a);
		write(1, "sa\n", 3);
		return (1);
	}
	return (0);
}

int	check_last_3_a(t_Intarr *a)
{
	if (a->arr[0] < a->arr[1] && a->arr[0] < a->arr[2] && a->arr[1] > a->arr[2])
	{
		sa(a);
		rx(a);
		write(1, "sa\nra\n", 6);
		return (1);
	}
	if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] < a->arr[2])
	{
		rx(a);
		write(1, "ra\n", 3);
		return (1);
	}
	if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2] && a->arr[1] > a->arr[2])
	{
		rx(a);
		sa(a);
		write(1, "ra\nsa\n", 6);
		return (1);
	}
	if (check_last_3_a1(a))
		return (1);
	return (0);
}

int	get_small_a(t_Intarr *a)
{
	int	min_value;
	int	i;
	int	j;

	i = 1;
	j = 0;
	min_value = a->arr[0];
	while (i < a->size)
	{
		if (a->arr[i] < min_value)
		{
			min_value = a->arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

int	get_greater_b(t_Intarr *b)
{
	int	max_value;
	int	i;
	int	j;

	i = 1;
	j = 0;
	max_value = b->arr[0];
	while (i < b->size)
	{
		if (b->arr[i] > max_value)
		{
			max_value = b->arr[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	search_small(int x, t_Intarr *a, int *small)
{
	int	i;
	int	f_l;
	int	lower;

	i = 0;
	f_l = 1;
	while (i < a->size)
	{
		if (a->arr[i] > x)
		{
			if (f_l)
				lower = a->arr[i];
			f_l = 0;
			if (a->arr[i] <= lower)
			{
				lower = a->arr[i];
				*small = i;
			}
		}
		i++;
	}
	if (*small == -1)
		*small = get_small_a(a);
}
