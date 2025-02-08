/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 00:45:17 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/08 02:44:28 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_return_nbr(char *str, int i, int sign)
{
	long int	nbr;

	nbr = 0;
	while ((str[i] != '\0') && (ft_isdigit(str[i]) == 1))
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (sign == '-')
		return ((nbr * -1));
	else
		return (nbr);
}

long int	ft_atol(char *str)
{
	int		i;
	char	sign;

	sign = '0';
	i = 0;
	while (str[i] != '\0' && (ft_isspace(str[i]) == 1))
		i++;
	if ((str[i] != '\0') && (str[i] == '+' || str[i] == '-'))
	{
		sign = str[i];
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
		return (0);
	return (ft_return_nbr(str, i, sign));
}
