/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:24 by agaga             #+#    #+#             */
/*   Updated: 2025/02/08 16:40:03 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Sort if there are only three elements in the stack.
void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->nbr)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
	else if (ft_max(*stack_a) == (*stack_a)->nbr)
	{
		ft_ra(stack_a);
		if (!ft_check_if_sorted(*stack_a))
			ft_sa(stack_a);
	}
	else
	{
		if (ft_index(*stack_a, ft_max(*stack_a)) == 1)
			ft_rra(stack_a);
		else
			ft_sa(stack_a);
	}
}
