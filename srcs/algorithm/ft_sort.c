/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:13:14 by agaga             #+#    #+#             */
/*   Updated: 2025/01/13 22:36:35 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function pushes elements from stack_a to stack_b
// until only three elements remain in stack_a. During this
// process, it ensures that stack_b is sorted. Once only
// three elements are left in stack_a, it calls the 
// ft_sort_three function to sort these remaining elements.
t_stack	*ft_push_to_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (ft_lstsize(*stack_a) > 3 && !ft_checksorted(*stack_a))
		ft_pb(stack_a, &stack_b, 0);
	if (!ft_checksorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

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
			if (i == calculate_cost_a(*a, *b, tmp->nbr, RA_RB))
				i = rotate_both_up(a, b, tmp->nbr, 'b');
			else if (i == calculate_cost_a(*a, *b, tmp->nbr, RA_RRB))
				i = rotate_a_up_b_down(a, b, tmp->nbr, 'b');
			else if (i == calculate_cost_a(*a, *b, tmp->nbr, RRA_RRB))
				i = rotate_both_down(a, b, tmp->nbr, 'b');
			else if (i == calculate_cost_a(*a, *b, tmp->nbr, RRA_RB))
				i = rotate_a_down_b_up(a, b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

// This function sorts the stack_a if there are more 
// than 2 elements in the stack_a.
// And finally it makes final sort in stack_a after
// all values pushed to stack_b, sorted and pushed
// back to stack_a. Because, even the stack_a is
// sorted at the end, the minimum number have to 
// at the top of the stack_a. So, it simply brings
// the smallest number of the stack_a to the top.
void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_lstsize(*stack_a) == 2)
		ft_sa(stack_a, 0);
	else
	{
		stack_b = ft_push_to_b(stack_a);
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
