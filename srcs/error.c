/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:27 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/10 13:00:12 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	is_ascending(t_Intarr *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_repeat(t_Intarr *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->arr[i] == a->arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(t_Intarr *a)
{
	if (is_ascending(a))
		return (1);
	if (is_repeat(a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
