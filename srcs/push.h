/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:46:00 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/10 04:40:49 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"

# define MAX_VAL 2147483648
# define MIN_VAL -2147483649

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

//int
int		all_free(t_Intarr *a_main, t_Intarr *b, char **str, int argc);
int		pa(t_Intarr *a, t_Intarr *b);
int		pb(t_Intarr *a, t_Intarr *b);
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
int		got_to_a(t_Intarr *a);
int		go_to_b(t_Intarr *b);
int		back_to_a(t_Intarr *a, t_Intarr *b);
int		handle_atol(char *str);
int		go_to_handle(int argc, t_Intarr *a_main, char **str, char **argv);
int		go_to_work(t_Intarr *a, t_Intarr *b);

//void
void	go_to_loop(t_Intarr *b, t_Intarr *a);
void	ft_free(char **str, int i);
void	search_operation(t_Intarr *a, t_Intarr *b,
			int *i_lower, int *i_greater);
void	sa(t_Intarr *a);
void	ra(t_Intarr *a);
void	rra(t_Intarr *a);
void	rr(t_Intarr *a, t_Intarr *b);
void	rrr(t_Intarr *a, t_Intarr *b);
void	go_to_greater(int lower, int greater, t_Intarr *a);
void	compare_random(int lower, int greater, t_Intarr *a, t_Intarr *b);
void	search_small(int x, t_Intarr *a, int *small);

//char
char	**copy(int argc, char **argv);

#endif
