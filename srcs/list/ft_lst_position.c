/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:06:23 by agaga             #+#    #+#             */
/*   Updated: 2025/02/04 00:06:36 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	ft_pos_a(t_stack *stack_a, int nbr)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (stack_a && nbr < stack_a->nbr && nbr > ft_lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr > ft_max(stack_a) || nbr < ft_min(stack_a))
		i = ft_index(stack_a, ft_min(stack_a));
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

int	ft_pos_b(t_stack *stack_b, int nbr)
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
