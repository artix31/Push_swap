/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swaping.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:44:50 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/12 13:51:19 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	sum_operation(t_Intarr *a, t_Intarr *b, int lower, int greater)
{
	int	up;
	int	down;

	up = greater;
	down = lower;
	if (lower <= b->size / 2 && greater <= a->size / 2)
	{
		if (greater > lower)
			return (greater);
		return (lower);
	}
	if (lower > b->size / 2 && greater > a->size / 2)
	{
		up = a->size - greater;
		down = b->size - lower;
		if (up > down)
			return (up);
		return (down);
	}
	if (lower > (b->size / 2))
		down = b->size - lower;
	if (greater > (a->size / 2))
		up = a->size - greater;
	return (up + down);
}

void	go_to_loop(t_Intarr *b, t_Intarr *a)
{
	a->j = 0;
	a->lower = 0;
	while (a->j < b->size)
	{
		if (b->arr[a->j] < a->arr[a->i])
		{
			if (a->f_l)
			{
				a->lower = b->arr[a->j];
				a->f_l = 0;
			}
			if (b->arr[a->j] >= a->lower)
			{
				a->lower = b->arr[a->j];
				a->test_lower = a->j;
				a->test_greater = a->i;
			}
		}
		a->j++;
	}
}

void	search_operation(t_Intarr *a, t_Intarr *b, int *i_lower, int *i_greater)
{
	a->f_l = 1;
	a->jk = 1;
	a->i = 0;
	a->sum = 0;
	while (a->i < a->size)
	{
		go_to_loop(b, a);
		if (a->lower == 0)
		{
			a->test_lower = get_greater_b(b);
			a->test_greater = a->i;
		}
		if (a->jk
			|| sum_operation(a, b, a->test_lower, a->test_greater) < a->sum)
		{
			a->sum = sum_operation(a, b, a->test_lower, a->test_greater);
			*i_lower = a->test_lower;
			*i_greater = a->test_greater;
			a->jk = 0;
		}
		a->f_l = 1;
		a->i++;
	}
}

int	back_to_a(t_Intarr *a, t_Intarr *b)
{
	int	small;

	while (b->size)
	{
		small = -1;
		search_small(b->arr[0], a, &small);
		go_to_greater(0, small, a);
		if (!pa(a, b))
			return (0);
	}
	while (a->arr[a->size - 1] < a->arr[0])
	{
		rrx(a);
		write(1, "rra\n", 4);
	}
	return (1);
}

int	sort(t_Intarr *a, t_Intarr *b)
{
	int	i_lower;
	int	i_greater;
	int	up;
	int	down;

	if (!pb(a, b))
		return (0);
	if (!pb(a, b))
		return (0);
	while (a->size > 3)
	{
		i_lower = -1;
		i_greater = -1;
		search_operation(a, b, &i_lower, &i_greater);
		up = compare_up(i_lower, i_greater, a, b);
		down = compare_down(i_lower, i_greater, a, b);
		if (!up && !down)
			compare_random(i_lower, i_greater, a, b);
		if (!pb(a, b))
			return (0);
	}
	check_last_3_a(a);
	if (!back_to_a(a, b))
		return (0);
	return (1);
}
