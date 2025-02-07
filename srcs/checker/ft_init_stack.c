/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:43:30 by agaga             #+#    #+#             */
/*   Updated: 2025/02/07 16:29:24 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Initialize the stack with the input arguments 
// if there is only two argument, parse the quoted arguments 
// if there are multiple arguments, check if the arguments are valid
// then add the arguments to the stack
static void	process_tokens(char **tokens, t_stack **a)
{
	int		j;
	long	num;
	t_stack	*tmp;

	j = 0;
	while (tokens[j])
	{
		if (is_valid_number_format(tokens[j]) == 0)
			ft_freeerror(tokens, a);
		num = ft_atol(tokens[j]);
		if (num > INT_MAX || num < INT_MIN)
			ft_freeerror(tokens, a);
		tmp = ft_stack_new((int)num);
		if (!tmp)
			ft_freeerror(tokens, &tmp);
		ft_lstadd_back(a, tmp);
		j++;
	}
}

t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*a;
	char	**tokens;
	int		i;

	a = NULL;
	i = 0;
	while (++i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!tokens || !tokens[0])
			ft_freeerror(tokens, &a);
		process_tokens(tokens, &a);
		ft_freestr(tokens);
		free(tokens);
	}
	if (has_duplicates(a))
	{
		ft_free(&a);
		ft_error();
	}
	return (a);
}
