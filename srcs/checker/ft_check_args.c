/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:43:46 by agaga             #+#    #+#             */
/*   Updated: 2025/02/08 16:40:33 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Check if the input is a valid number format
int	is_valid_number_format(const char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		has_digit = 1;
		i++;
	}
	return (has_digit);
}

// Check if there are duplicates in the stack
int	has_duplicates(t_stack *a)
{
	t_stack	*current;
	t_stack	*runner;

	current = a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->nbr == runner->nbr)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

// Check if the stack is sorted in ascending order
// by comparing the current number with the next number
int	ft_check_if_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->nbr;
	while (stack_a)
	{
		if (i > stack_a->nbr)
			return (0);
		i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
