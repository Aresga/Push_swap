/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:12:53 by agaga             #+#    #+#             */
/*   Updated: 2025/02/04 00:13:21 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotates both stacks upward until target position is reached AKA RA_RB
int	rotate_both_up(t_stack **a, t_stack **b, int c)
{
	while ((*b)->nbr != c && ft_pos_a(*a, c) > 0)
		ft_rr(a, b, 0);
	while ((*b)->nbr != c)
		ft_rb(b, 0);
	while (ft_pos_a(*a, c) > 0)
		ft_ra(a, 0);
	ft_pa(a, b, 0);
	return (-1);
}

// Rotates both stacks downward until target position is reached AKA RRA_RRB
int	rotate_both_down(t_stack **a, t_stack **b, int c)
{
	while ((*b)->nbr != c && ft_pos_a(*a, c) > 0)
		ft_rrr(a, b, 0);
	while ((*b)->nbr != c)
		ft_rrb(b, 0);
	while (ft_pos_a(*a, c) > 0)
		ft_rra(a, 0);
	ft_pa(a, b, 0);
	return (-1);
}

// Rotates stack A down while rotating B up AKA RRA_RB
int	rotate_a_down_b_up(t_stack **a, t_stack **b, int c)
{
	while (ft_pos_a(*a, c) > 0)
		ft_rra(a, 0);
	while ((*b)->nbr != c)
		ft_rb(b, 0);
	ft_pa(a, b, 0);
	return (-1);
}

// Rotates stack A up while rotating B down AKA RA_RRB 
int	rotate_a_up_b_down(t_stack **a, t_stack **b, int c)
{
	while (ft_pos_a(*a, c) > 0)
		ft_ra(a, 0);
	while ((*b)->nbr != c)
		ft_rrb(b, 0);
	ft_pa(a, b, 0);
	return (-1);
}
