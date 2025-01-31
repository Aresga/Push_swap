/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:14 by agaga             #+#    #+#             */
/*   Updated: 2025/01/30 21:00:48 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function is pushing back the elements from stack_b
// to stack_a until stack_b is empty. 
t_stack	**ft_push_to_a(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		i = calculate_rotation_ba(*a, *b);
		while (i >= 0)
		{
			if (i == calculate_cost(*a, *b, tmp->nbr, RA_RB))
				i = rotate_both_up(a, b, tmp->nbr, 'b');
			else if (i == calculate_cost(*a, *b, tmp->nbr, RA_RRB))
				i = rotate_a_up_b_down(a, b, tmp->nbr, 'b');
			else if (i == calculate_cost(*a, *b, tmp->nbr, RRA_RRB))
				i = rotate_both_down(a, b, tmp->nbr, 'b');
			else if (i == calculate_cost(*a, *b, tmp->nbr, RRA_RB))
				i = rotate_a_down_b_up(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

// Helper function to check if there are any numbers below max in stack
int	has_numbers_below(t_stack *stack, int max)
{
	while (stack)
	{
		if (stack->nbr <= max)
			return (1);
		stack = stack->next;
	}
	return (0);
}

// 
void	ft_push_chucks_to_b(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	chunk_size;
	int	current_max;
	int	mid_chunk;

	min = ft_min(*a);
	max = ft_max(*a);
	chunk_size = (max - min) / 3;
	current_max = min + chunk_size;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->nbr <= current_max)
		{
			ft_pb(a, b, 0);
			mid_chunk = min + (chunk_size / 2);
			if ((*b)->nbr < mid_chunk)
				ft_rb(b, 0);
		}
		else
			ft_ra(a, 0);
		if (!has_numbers_below(*a, current_max))
			current_max += chunk_size;
	}
}

// the main sorting function
// if the stack has only two elements, swap them
// if the stack has more than two elements, push the chuncks to stack_b
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		ft_push_chucks_to_b(stack_a, &stack_b);
		if (!ft_check_sorted(*stack_a))
			ft_sort_three(stack_a);
		stack_a = ft_push_to_a(stack_a, &stack_b);
		i = ft_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_ra(stack_a, 0);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_rra(stack_a, 0);
		}
	}
}
