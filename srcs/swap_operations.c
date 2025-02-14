/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:01 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/13 20:55:44 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//sa (swap a): Swap the first 2 elements at
//the top of stack a.
//Do nothing if there is only one
//or no elements.
void	sa(t_Intarr *a)
{
	int	temp;

	temp = a->arr[0];
	a->arr[0] = a->arr[1];
	a->arr[1] = temp;
}

//rrx (reverse rotate x(whether a or b)):
//Shift down all elements of stack x by 1.
//The last element becomes the first one.
void	rrx(t_Intarr *a)
{
	int	n;
	int	i;
	int	first;

	n = a->size;
	i = n - 1;
	first = a->arr[n - 1];
	while (i > 0)
	{
		a->arr[i] = a->arr[i - 1];
		i--;
	}
	a->arr[0] = first;
}

// rx (rotate a || rotate b): Shift
//up all elements of stack a/b by 1.
//The first element becomes the last one,
//input the name of the stack.
void	rx(t_Intarr *a)
{
	int	n;
	int	i;
	int	last;

	n = a->size;
	i = 0;
	last = a->arr[0];
	while (i < (n - 1))
	{
		a->arr[i] = a->arr[i + 1];
		i++;
	}
	a->arr[n - 1] = last;
}

//pb (push b): Take the first element
//at the top of a and put it at the top of b.
//Do nothing if a is empty
int	got_to_a(t_Intarr *a)
{
	t_Intarr	new_a;
	int			i;

	new_a.arr = malloc((a->size - 1) * sizeof(int));
	if (new_a.arr == NULL && a->size > 1)
		return (0);
	i = 1;
	while (i < a->size)
	{
		new_a.arr[i - 1] = a->arr[i];
		i++;
	}
	free(a->arr);
	a->arr = new_a.arr;
	a->size--;
	write(1, "pb\n", 3);
	return (1);
}

//pa (push a): Take the first element at
//the top of b and put it at the top of a.
//Do nothing if b is empty.
int	go_to_b(t_Intarr *b)
{
	t_Intarr	new_b;
	int			i;

	new_b.arr = malloc((b->size - 1) * sizeof(int));
	if (new_b.arr == NULL && b->size > 1)
		return (0);
	i = 1;
	while (i < b->size)
	{
		new_b.arr[i - 1] = b->arr[i];
		i++;
	}
	free(b->arr);
	b->arr = new_b.arr;
	b->size--;
	write(1, "pa\n", 3);
	return (1);
}
