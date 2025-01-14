/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:43:46 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 19:11:04 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	is_valid_number_format(const char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			has_digit = 1;
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (has_digit);
}

static int	has_duplicates(char **av)
{
	int		i;
	int		j;
	long	num1;
	long	num2;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		num1 = ft_atol(av[i]);
		while (av[j])
		{
			num2 = ft_atol(av[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	if (!av || !av[1])
		return (0);
	while (av[i])
	{
		if (!is_valid_number_format(av[i]))
			return (0);
		i++;
	}
	if (has_duplicates(av))
		return (0);
	return (1);
}
