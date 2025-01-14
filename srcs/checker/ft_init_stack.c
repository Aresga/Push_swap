/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:43:30 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 19:25:11 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_parse_quoted_args(char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;

	if (av[1][0] == NULL)
		exit(0);
	stack_a = NULL;
	tmp = ft_split(av[1], ' ');
	i = 0;
	while (tmp[i])
	{
		ft_lstadd_back(&stack_a, ft_stack_new(ft_atol(tmp[i])));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (stack_a);
}

t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (ac == 2)
		a = ft_parse_quoted_args(av);
	else
	{
		while (i < ac)
		{
			ft_lstadd_back(&a, ft_stack_new(ft_atol(av[i])));
			i++;
		}
	}
	return (a);
}
