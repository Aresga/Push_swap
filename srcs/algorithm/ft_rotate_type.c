/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:05 by agaga             #+#    #+#             */
/*   Updated: 2025/01/12 20:55:01 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	int		cost;
	t_stack	*tmp;

	tmp = b;
	i = calculate_cost_a(a, b, b->nbr, RRA_RRB);
	while (tmp)
	{
		cost = calculate_cost_a(a, b, tmp->nbr, RA_RB);
		if (i > cost)
			i = cost;
		cost = calculate_cost_a(a, b, tmp->nbr, RRA_RRB);
		if (i > cost)
			i = cost;
		cost = calculate_cost_a(a, b, tmp->nbr, RA_RRB);
		if (i > cost)
			i = cost;
		cost = calculate_cost_a(a, b, tmp->nbr, RRA_RB);
		if (i > cost)
			i = cost;
		tmp = tmp->next;
	}
	return (i);
}

// This function calculates and decides which rotation
// combination is best to use to sort the stack. Of
// course, after rotation there is always one push
// operation left to do, which is embedded in the code.
// Function is used during push from A to B.
int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	int		cost;
	t_stack	*tmp;

	tmp = a;
	i = calculate_cost(a, b, a->nbr, RRA_RRB);
	while (tmp)
	{
		cost = calculate_cost(a, b, tmp->nbr, RA_RB);
		if (i > cost)
			i = cost;
		cost = calculate_cost(a, b, tmp->nbr, RRA_RRB);
		if (i > cost)
			i = cost;
		cost = calculate_cost(a, b, tmp->nbr, RA_RRB);
		if (i > cost)
			i = cost;
		cost = calculate_cost(a, b, tmp->nbr, RRA_RB);
		if (i > cost)
			i = cost;
		tmp = tmp->next;
	}
	return (i);
}
