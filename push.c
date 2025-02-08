/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:44:15 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/08 03:44:19 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "./libft/libft.h"

int	go_to_work(t_Intarr *a, t_Intarr *b)
{
	if (a->size == 2)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
	if (a->size == 3)
		check_last_3_a(a);
	if (a->size == 4)
	{
		if (!pb(a, b))
			return (0);
		check_last_3_a(a);
		if (!back_to_a(a, b))
			return (0);
	}
	if (a->size > 4)
	{
		if (!sort(a, b))
			return (0);
	}
	return (1);
}

int	go_to_handle(int argc, t_Intarr *a_main, char **str, char **argv)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (i < argc - 1)
	{
		if (handle_digit(str[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		a_main->arr[i] = ft_atoll(argv[i + 1]);
		i++;
	}
	if (check_error(a_main))
		return (0);
	return (1);
}

int	all_free_with_error(t_Intarr *a_main, t_Intarr *b, char **str, int argc)
{
	if (str)
		ft_free(str, argc - 1);
	if (b)
	{
		if (b->arr)
			free(b->arr);
		free(b);
	}
	if (a_main)
	{
		if (a_main->arr)
			free(a_main->arr);
		free(a_main);
	}
	write(1, "Error\n", 6);
	return (0);
}

int	all_free(t_Intarr *a_main, t_Intarr *b, char **str, int argc)
{
	if (str)
		ft_free(str, argc - 1);
	if (b->arr)
		free(b->arr);
	free(a_main->arr);
	free(a_main);
	free(b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_Intarr	*a_main;
	t_Intarr	*b;
	char		**str;

	b = malloc(sizeof(t_Intarr));
	if (!b)
		return (all_free_with_error(NULL, b, NULL, argc));
	b->arr = NULL;
	b->size = 0;
	a_main = malloc(sizeof(t_Intarr));
	if (!a_main)
		return (all_free_with_error(a_main, b, NULL, argc));
	a_main->arr = malloc((argc - 1) * sizeof(int));
	if (!a_main->arr)
		return (all_free_with_error(a_main, b, NULL, argc));
	a_main->size = argc - 1;
	str = copy(argc, argv);
	if (!go_to_handle(argc, a_main, str, argv))
		return (all_free(a_main, b, str, argc));
	go_to_work(a_main, b);
	all_free(a_main, b, str, argc);
	return (0);
}
