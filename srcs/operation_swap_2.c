/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:09 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/10 13:07:33 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//prepares the number to be pushed to 'b'
int	pb(t_Intarr *a, t_Intarr *b)
{
	t_Intarr	new_b;
	int			i;

	i = 0;
	new_b.arr = malloc((b->size + 1) * sizeof(int));
	if (!new_b.arr)
		return (0);
	new_b.arr[0] = a->arr[0];
	while (i < b->size)
	{
		new_b.arr[i + 1] = b->arr[i];
		i++;
	}
	b->size++;
	if (b->arr)
		free(b->arr);
	b->arr = new_b.arr;
	if (!got_to_a(a))
		return (0);
	return (1);
}

//prepares the number to be pushed to 'a'
int	pa(t_Intarr *a, t_Intarr *b)
{
	t_Intarr	new_a;
	int			i;

	new_a.arr = malloc((a->size + 1) * sizeof(int));
	if (new_a.arr == NULL)
		return (0);
	new_a.arr[0] = b->arr[0];
	i = 0;
	while (i < a->size)
	{
		new_a.arr[i + 1] = a->arr[i];
		i++;
	}
	a->size++;
	free(a->arr);
	a->arr = new_a.arr;
	if (!go_to_b(b))
		return (0);
	return (1);
}

//rr : ra and rb at the same time.
void	rr(t_Intarr *a, t_Intarr *b)
{
	rx(a);
	rx(b);
	write(1, "rr\n", 3);
}

//rrr : rra and rrb at the same time.
void	rrr(t_Intarr *a, t_Intarr *b)
{
	rrx(a);
	rrx(b);
	write(1, "rrr\n", 4);
}
