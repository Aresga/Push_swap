/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:12:53 by agaga             #+#    #+#             */
/*   Updated: 2025/02/06 18:59:21 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Rotates both stacks upward until target position is reached AKA RA_RB
int	rotate_both_up(t_stack **a, t_stack **b, int c)
{
	while ((*b)->nbr != c && ft_pos_a(*a, c) > 0)
		ft_rr(a, b);
	while ((*b)->nbr != c)
		ft_rb(b);
	while (ft_pos_a(*a, c) > 0)
		ft_ra(a);
	ft_pa(a, b);
	return (-1);
}

// Rotates both stacks downward until target position is reached AKA RRA_RRB
int	rotate_both_down(t_stack **a, t_stack **b, int c)
{
	while ((*b)->nbr != c && ft_pos_a(*a, c) > 0)
		ft_rrr(a, b);
	while ((*b)->nbr != c)
		ft_rrb(b);
	while (ft_pos_a(*a, c) > 0)
		ft_rra(a);
	ft_pa(a, b);
	return (-1);
}

// Rotates stack A down while rotating B up AKA RRA_RB
int	rotate_a_down_b_up(t_stack **a, t_stack **b, int c)
{
	while (ft_pos_a(*a, c) > 0)
		ft_rra(a);
	while ((*b)->nbr != c)
		ft_rb(b);
	ft_pa(a, b);
	return (-1);
}

// Rotates stack A up while rotating B down AKA RA_RRB 
int	rotate_a_up_b_down(t_stack **a, t_stack **b, int c)
{
	while (ft_pos_a(*a, c) > 0)
		ft_ra(a);
	while ((*b)->nbr != c)
		ft_rrb(b);
	ft_pa(a, b);
	return (-1);
}
