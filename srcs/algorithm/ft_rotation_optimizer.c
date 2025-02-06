/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_optimizer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:05 by agaga             #+#    #+#             */
/*   Updated: 2025/02/06 18:44:17 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**
 * calculate_cost - Calculates the cost of moving an element in the stack.
 * @a: Pointer to the first stack.
 * @b: Pointer to the second stack.
 * @c: The element to be moved.
 * @dir: The direction of the move.
 *
 * Return: The cost of the move.
 */
int	calculate_cost(t_stack *a, t_stack *b, int c, t_direction dir)
{
	t_cache	cache;

	cache.size_a = ft_lstsize(a);
	cache.size_b = ft_lstsize(b);
	cache.pos_a = ft_pos_a(a, c);
	cache.pos_b = ft_index(b, c);
	if (dir == RA_RB)
	{
		cache.cost = cache.pos_a;
		if (cache.cost < cache.pos_b)
			cache.cost = cache.pos_b;
	}
	else if (dir == RRA_RRB)
	{
		cache.cost = cache.size_a - cache.pos_a;
		if (cache.cost < (cache.size_b - cache.pos_b))
			cache.cost = cache.size_b - cache.pos_b;
	}
	else if (dir == RA_RRB)
		cache.cost = cache.pos_a + (cache.size_b - cache.pos_b);
	else if (dir == RRA_RB)
		cache.cost = (cache.size_a - cache.pos_a) + cache.pos_b;
	return (cache.cost);
}

// this function calcualte the cost of rotating stack_a and stack_b
// using 4 diff strategies and return the minimum cost of the 4
int	calculate_min_cost(t_stack *a, t_stack *b)
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
