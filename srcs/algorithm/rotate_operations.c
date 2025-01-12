/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:12:53 by agaga             #+#    #+#             */
/*   Updated: 2025/01/12 16:46:31 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotates both stacks upward until target position is reached
int	rotate_both_up(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_pos_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->nbr != c)
			ft_ra(a, 0);
		while (ft_pos_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_pos_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->nbr != c)
			ft_rb(b, 0);
		while (ft_pos_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// Rotates both stacks downward until target position is reached
int	rotate_both_down(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && ft_pos_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->nbr != c)
			ft_rra(a, 0);
		while (ft_pos_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->nbr != c && ft_pos_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->nbr != c)
			ft_rrb(b, 0);
		while (ft_pos_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// Rotates stack A down while rotating B up
int	rotate_a_down_b_up(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_rra(a, 0);
		while (ft_pos_b(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_pos_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->nbr != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

// Rotates stack A up while rotating B down
int	rotate_a_up_b_down(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ft_ra(a, 0);
		while (ft_pos_b(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_pos_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->nbr != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
