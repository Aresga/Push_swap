/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:07:59 by agaga             #+#    #+#             */
/*   Updated: 2025/02/08 16:09:59 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Helper function: Reverse rotate a single stack.
void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*previous;
	t_stack	*current;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	previous = NULL;
	current = *stack;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	previous->next = NULL;
}

// rrr: Reverse rotate both stacks simultaneously.
void	ft_rrr(t_stack **a, t_stack **b)
{
	if ((!a || !(*a) || !((*a)->next))
		|| (!b || !(*b) || !((*b)->next)))
		return ;
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
