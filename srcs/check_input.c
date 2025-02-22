/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:45 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/13 20:11:52 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//frees an array, give arr and curr size(lower than or equals max size)
void	ft_free(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

//used only once, copies argc into the array (stack A)
char	**copy(int argc, char **argv)
{
	char	**str;
	int		i;

	str = (char **)malloc(argc * sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		str[i] = ft_strdup(argv[i + 1]);
		if (!str[i])
		{
			ft_free(str, i);
			return (NULL);
		}
		i++;
	}
	str[argc - 1] = NULL;
	return (str);
}

//Handles Atol (nbr > && < UL_MAX/UL_MIN)
//then rejects any nbr > || < Max_int/MIN_int,
//return 1 on Err, 0 on success
int	handle_atol(char *str)
{
	if (ft_atol(str) >= MAX_VAL || ft_atol(str) < MIN_VAL)
		return (1);
	else
		return (0);
}
