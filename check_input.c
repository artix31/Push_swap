/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:45:45 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/08 03:45:46 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
#include "./libft/libft.h"

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

void	remove_zeros(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] == '0')
		i++;
	while (str[i] != '\0')
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	if (j == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
}

int	go_to_second_handle(char *str)
{
	remove_zeros(str);
	if (ft_strlen(str) < 10)
		return (0);
	if (ft_strlen(str) == 10 && ft_strncmp("2147483648", str, 10) >= 0)
		return (0);
	else
		return (1);
}

int	handle_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		while (str[i + 1] != '\0')
		{
			str[i] = str[i + 1];
			i++;
		}
		str[i] = '\0';
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (go_to_second_handle(str));
}
