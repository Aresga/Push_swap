/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:06:42 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 14:01:25 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function returns the last element of the stack.
t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// This function returns the size of the stack.
int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// Function to add a new node to the stack from back side
void	ft_lstadd_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(ft_lstlast(*stack))->next = stack_new;
}

// While arguments are valid, we start to add them 
// into stack here one by one with while loop.
// Atoi takes the number and turn it into an integer 
// value where we can make math operations.
// With stack new we create a new node for the current 
// argument without linking it to list.
// We make linking stage in ft_lstadd_back call.
void	list_args(char **av, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (av[i] != NULL)
	{
		ft_lstadd_back(stack_a, ft_stack_new(ft_atoi(av[i])));
		i++;
	}
}

// Creates new stack node with given number.
t_stack	*ft_stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}
