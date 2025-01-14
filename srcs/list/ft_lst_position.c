/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:06:23 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 15:33:08 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function finds the index of the number in the stack.
int	ft_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == nbr)
			return (i);
		i++;
		a = a->next;
	}
	return (0);
}

// This function finds the correct place of the number in stack_a.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_a.
int	ft_pos_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		i = ft_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

// This function finds the correct place of the number in stack_b.
// In other words, it check what index number nbr_push will get 
// after it is being pushed to the stack_b.
int	ft_pos_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;
	t_stack	*current;

	if (!stack_b)
		return (0);
	i = 0;
	if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		return (ft_index(stack_b, ft_max(stack_b)));
	current = stack_b;
	tmp = stack_b->next;
	while (tmp)
	{
		if (nbr_push < current->nbr && nbr_push > tmp->nbr)
			return (i + 1);
		current = current->next;
		tmp = tmp->next;
		i++;
	}
	if (nbr_push < ft_lstlast(stack_b)->nbr && nbr_push > stack_b->nbr)
		return (0);
	return (i);
}
