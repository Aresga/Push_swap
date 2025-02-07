/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:11:21 by agaga             #+#    #+#             */
/*   Updated: 2025/02/07 16:28:48 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Function to free the stack
void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// Function to free the string list 
void	ft_freestr(char **lst)
{
	char	*current_str;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		current_str = *lst;
		lst++;
		free(current_str);
	}
	*lst = NULL;
}

void	ft_freeerror(char **tokens, t_stack **a)
{
	ft_freestr(tokens);
	free(tokens);
	ft_free(a);
	ft_error();
}
