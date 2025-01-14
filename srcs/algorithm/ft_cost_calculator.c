/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:15:49 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 17:21:50 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calculate_cost(t_stack *a, t_stack *b, int c, t_direction dir)
{
	int	cost;

	cost = 0;
	if (dir == RA_RB)
	{
		cost = ft_pos_a(a, c);
		if (cost < ft_index(b, c))
			cost = ft_index(b, c);
	}
	else if (dir == RRA_RRB)
	{
		cost = ft_lstsize(a) - ft_pos_a(a, c);
		if (cost < (ft_lstsize(b) - ft_index(b, c)))
			cost = ft_lstsize(b) - ft_index(b, c);
	}
	else if (dir == RA_RRB)
	{
		cost = ft_pos_a(a, c) + (ft_lstsize(b) - ft_index(b, c));
	}
	else if (dir == RRA_RB)
	{
		cost = (ft_lstsize(a) - ft_pos_a(a, c)) + ft_index(b, c);
	}
	return (cost);
}
