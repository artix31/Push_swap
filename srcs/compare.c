/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:34 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/08 03:45:37 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	compare_up(int lower, int greater, t_Intarr *a, t_Intarr *b)
{
	if (lower <= b->size / 2 && greater <= a->size / 2
		&& lower != -1 && greater != -1)
	{
		while (lower && greater)
		{
			rr(a, b);
			lower--;
			greater--;
		}
		while (lower)
		{
			ra(b);
			lower--;
			write(1, "rb\n", 3);
		}
		while (greater)
		{
			ra(a);
			greater--;
			write(1, "ra\n", 3);
		}
		return (1);
	}
	return (0);
}

int	compare_down(int lower, int greater, t_Intarr *a, t_Intarr *b)
{
	if (lower > b->size / 2 && greater > a->size / 2 && lower != -1
		&& greater != -1)
	{
		lower = b->size - lower;
		greater = a->size - greater;
		while (lower && greater)
		{
			rrr(a, b);
			lower--;
			greater--;
		}
		while (lower--)
		{
			rra(b);
			write(1, "rrb\n", 4);
		}
		while (greater--)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
		return (1);
	}
	return (0);
}

void	go_to_greater(int lower, int greater, t_Intarr *a)
{
	if (greater <= a->size / 2 && lower != -1 && greater != -1)
	{
		while (greater)
		{
			ra(a);
			greater--;
			write(1, "ra\n", 3);
		}
	}
	if (greater > a->size / 2 && lower != -1 && greater != -1)
	{
		greater = a->size - greater;
		while (greater)
		{
			rra(a);
			greater--;
			write(1, "rra\n", 4);
		}
	}
}

void	compare_random(int lower, int greater, t_Intarr *a, t_Intarr *b)
{
	if (lower <= b->size / 2 && lower != -1 && greater != -1)
	{
		while (lower)
		{
			ra(b);
			lower--;
			write(1, "rb\n", 3);
		}
	}
	if (lower > b->size / 2 && lower != -1 && greater != -1)
	{
		lower = b->size - lower;
		while (lower)
		{
			rra(b);
			lower--;
			write(1, "rrb\n", 4);
		}
	}
	go_to_greater(lower, greater, a);
}
