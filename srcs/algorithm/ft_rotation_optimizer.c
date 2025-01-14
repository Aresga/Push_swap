/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_optimizer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:05 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 18:21:32 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	calculate_rotation_ba(t_stack *a, t_stack *b)
{
	int			min_cost;
	int			current_cost;
	t_stack		*tmp;
	t_direction	direction;
	t_cost		cost;

	tmp = b;
	min_cost = INT_MAX;
	while (tmp)
	{
		cost.ra_rb = calculate_cost(a, b, tmp->nbr, RA_RB);
		cost.rra_rrb = calculate_cost(a, b, tmp->nbr, RRA_RRB);
		cost.ra_rrb = calculate_cost(a, b, tmp->nbr, RA_RRB);
		cost.rra_rb = calculate_cost(a, b, tmp->nbr, RRA_RB);
		current_cost = ft_min_of_four(cost.ra_rb, cost.rra_rrb,
				cost.ra_rrb, cost.rra_rb);
		if (current_cost < min_cost)
			min_cost = current_cost;
		tmp = tmp->next;
	}
	return (min_cost);
}
