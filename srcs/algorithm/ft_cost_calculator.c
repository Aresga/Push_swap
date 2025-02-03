/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:15:49 by agaga             #+#    #+#             */
/*   Updated: 2025/02/04 00:48:22 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
