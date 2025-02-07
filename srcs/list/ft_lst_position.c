/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:06:23 by agaga             #+#    #+#             */
/*   Updated: 2025/02/07 13:18:38 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// this function is used to find the index of the element in the stack
// by comparing the element with the current element in the stack
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

// this function is used to find the position of the element in stack a
// by comparing the element with the current and next element in the stack
int	ft_position_a(t_stack *stack_a, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (stack_a && nbr < stack_a->nbr && nbr > ft_lstlast(stack_a)->nbr)
		return (0);
	else if (nbr > ft_max(stack_a) || nbr < ft_min(stack_a))
		return (ft_index(stack_a, ft_min(stack_a)));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr || tmp->nbr < nbr)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}

// this function is used to find the position of the element in stack b
// by comparing the element with the current and next element in the stack
// if the element is greater than the current 
// element and less than the next element
// then the position is returned
int	ft_position_b(t_stack *stack_b, int nbr)
{
	t_stack	*tmp;
	t_stack	*current;
	int		position;

	if (!stack_b)
		return (0);
	position = 0;
	if (nbr > ft_max(stack_b) || nbr < ft_min(stack_b))
		return (ft_index(stack_b, ft_max(stack_b)));
	current = stack_b;
	tmp = stack_b->next;
	while (tmp && current)
	{
		if (nbr < current->nbr && nbr > tmp->nbr)
			return (position + 1);
		current = current->next;
		tmp = tmp->next;
		position++;
	}
	if (nbr < ft_lstlast(stack_b)->nbr && nbr > stack_b->nbr)
		return (0);
	return (position);
}
