/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:14 by agaga             #+#    #+#             */
/*   Updated: 2025/02/08 16:40:03 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// This function is pushing back the elements from stack_b
// to stack_a until stack_b is empty. 
t_stack	**ft_push_to_a(t_stack **a, t_stack **b)
{
	int		min_cost;
	t_stack	*tmp;

	while (*b)
	{
		tmp = *b;
		min_cost = calculate_min_cost(*a, *b);
		while (min_cost >= 0)
		{
			if (min_cost == calculate_cost(*a, *b, tmp->nbr, RA_RB))
				min_cost = rotate_both_up(a, b, tmp->nbr);
			else if (min_cost == calculate_cost(*a, *b, tmp->nbr, RA_RRB))
				min_cost = rotate_a_up_b_down(a, b, tmp->nbr);
			else if (min_cost == calculate_cost(*a, *b, tmp->nbr, RRA_RRB))
				min_cost = rotate_both_down(a, b, tmp->nbr);
			else if (min_cost == calculate_cost(*a, *b, tmp->nbr, RRA_RB))
				min_cost = rotate_a_down_b_up(a, b, tmp->nbr);
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

// Pushes the chuncks to stack_b after dividing the stack into three parts
void	ft_push_chucks_to_b(t_stack **a, t_stack **b)
{
	long	min;
	long	max;
	long	chunk_size;
	long	current_max;
	long	mid_chunk;

	min = ft_min(*a);
	max = ft_max(*a);
	chunk_size = (max - min) / 3;
	current_max = min + chunk_size;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->nbr <= current_max)
		{
			ft_pb(a, b);
			mid_chunk = (min + (chunk_size / 2)) * (1 - (ft_lstsize(*a) >= 100))
				+ ((current_max) - (chunk_size / 2)) * (ft_lstsize(*a) >= 100);
			if ((*b)->nbr <= mid_chunk)
				ft_rb(b);
		}
		else
			ft_ra(a);
		if (!has_numbers_below(*a, current_max))
			current_max += chunk_size;
	}
}

// the main sorting function
// if the stack has only two elements, swap them
// if the stack has more than two elements, push the chuncks to stack_b
void	ft_sort(t_stack **stack_a)
{
	int		i;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a);
	else
	{
		ft_push_chucks_to_b(stack_a, &stack_b);
		if (!ft_check_if_sorted(*stack_a))
			ft_sort_three(stack_a);
		stack_a = ft_push_to_a(stack_a, &stack_b);
		i = ft_index(*stack_a, ft_min(*stack_a));
		if (i < ft_lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_ra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != ft_min(*stack_a))
				ft_rra(stack_a);
		}
	}
}
