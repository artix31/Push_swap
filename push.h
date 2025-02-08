/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:46:00 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/08 03:46:02 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_arr
{
	int		j;
	int		lower;
	int		i;
	int		f_l;
	int		sum;
	int		test_lower;
	int		test_greater;
	int		jk;
	int		*arr;
	int		size;
}			t_Intarr;

int		all_free(t_Intarr *a_main, t_Intarr *b, char **str, int argc);
void	go_to_loop(t_Intarr *b, t_Intarr *a);
void	ft_free(char **str, int i);
char	**copy(int argc, char **argv);
void	search_operation(t_Intarr *a, t_Intarr *b,
			int *i_lower, int *i_greater);
void	sa(t_Intarr *a);
void	rra(t_Intarr *a);
void	ra(t_Intarr *a);
void	rr(t_Intarr *a, t_Intarr *b);
void	rrr(t_Intarr *a, t_Intarr *b);
void	go_to_greater(int lower, int greater, t_Intarr *a);
void	compare_random(int lower, int greater, t_Intarr *a, t_Intarr *b);
void	search_small(int x, t_Intarr *a, int *small);
int		check_last_3_a1(t_Intarr *a);
int		check_last_3_a(t_Intarr *a);
int		get_small_a(t_Intarr *a);
int		get_greater_b(t_Intarr *b);
int		sum_operation(t_Intarr *a, t_Intarr *b, int lower, int greater);
int		is_ascending(t_Intarr *a);
int		is_reapet(t_Intarr *a);
int		compare_up(int lower, int greater, t_Intarr *a, t_Intarr *b);
int		compare_down(int lower, int greater, t_Intarr *a, t_Intarr *b);
int		check_error(t_Intarr *a);
int		sort(t_Intarr *a, t_Intarr *b);
int		pb(t_Intarr *a, t_Intarr *b);
int		pa(t_Intarr *a, t_Intarr *b);
int		got_to_a(t_Intarr *a);
int		go_to_b(t_Intarr *b);
int		back_to_a(t_Intarr *a, t_Intarr *b);
int		go_to_second_handle(char *str);
int		handle_digit(char *str);
int		go_to_handle(int argc, t_Intarr *a_main, char **str, char **argv);
int		go_to_work(t_Intarr *a, t_Intarr *b);

#endif
