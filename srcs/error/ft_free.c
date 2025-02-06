/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:11:21 by agaga             #+#    #+#             */
/*   Updated: 2025/02/06 18:44:17 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Function to free the stack
// I use a temporary variable to store the next node in the stack
// saving the next one in a temperary variable before freeing 
// the current one is usefull to avoid losing the next node
void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}

// Function to free the string list 
void	ft_freestr(char **lst)
{
	char	*current_str;

	if (!lst)
		return ;
	while (*lst)
	{
		current_str = *lst;
		lst++;
		free(current_str);
	}
	*lst = NULL;
}
