/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 02:54:27 by amashhad          #+#    #+#             */
/*   Updated: 2025/02/08 02:54:33 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%lld\n", ft_atoll(argv[1]));
	else
		return (write(1, "\n", 1));
	return (0);
}
