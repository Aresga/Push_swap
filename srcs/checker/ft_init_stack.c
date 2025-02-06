/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:43:30 by agaga             #+#    #+#             */
/*   Updated: 2025/02/06 18:44:17 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Parse the quoted arguments and add them to the stack 
// t_stack	*ft_parse_quoted_args(char **av)
// {
// 	t_stack	*stack_a;
// 	char	**tmp;
// 	int		i;

// 	stack_a = NULL;
// 	if (av[1][0] == '\0')
// 		exit(0);
// 	if (is_valid_number_format(av[1]) == 0)
// 		ft_error();
// 	tmp = ft_split(av[1], ' ');
// 	i = 0;
// 	while (tmp[i])
// 	{
// 		if (!check_args(tmp))
// 			ft_error();
// 		ft_lstadd_back(&stack_a, ft_stack_new(ft_atol(tmp[i])));
// 		i++;
// 	}
// 	ft_freestr(tmp);
// 	free(tmp);
// 	return (stack_a);
// }

// Initialize the stack with the input arguments 
// if there is only two argument, parse the quoted arguments 
// if there are multiple arguments, check if the arguments are valid
// then add the arguments to the stack
static void	process_tokens(char **tokens, t_stack **a)
{
	int		j;
	long	num;

	j = 0;
	while (tokens[j])
	{
		if (!is_valid_number_format(tokens[j]))
		{
			ft_freestr(tokens);
			ft_error();
		}
		num = ft_atol(tokens[j]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_freestr(tokens);
			ft_error();
		}
		ft_lstadd_back(a, ft_stack_new((int)num));
		j++;
	}
}

t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*a;
	char	**tokens;
	int		i;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		tokens = ft_split(av[i], ' ');
		if (!tokens || !tokens[0])
			ft_error();
		process_tokens(tokens, &a);
		ft_freestr(tokens);
		free(tokens);
		i++;
	}
	if (has_duplicates(a))
	{
		ft_free(&a);
		ft_error();
	}
	return (a);
}
