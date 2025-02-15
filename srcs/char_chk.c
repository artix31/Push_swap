/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:36:40 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/14 03:11:52 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_char_chk(char **argv, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < size)
	{
		while (argv[i][j] != '\0')
		{
			if (ft_strchr("0123456789+-", argv[i][j]))
				j++;
			else
				return (0);
		}
		j = 0;
		i++;
	}
	return (1);
}
