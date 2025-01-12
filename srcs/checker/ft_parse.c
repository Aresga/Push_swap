/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:19:35 by agaga             #+#    #+#             */
/*   Updated: 2025/01/12 21:05:45 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_freestr(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

t_stack	*ft_parse_args_quoted(char **av)
{
	t_stack	*stack_a;
	char	**tmp;
	int		i;

	stack_a = NULL;
	tmp = ft_split(av[1], ' ');
	i = 0;
	while (tmp[i])
	{
		ft_add_back(&stack_a, ft_stack_new(ft_atoi(tmp[i])));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (stack_a);
}

t_stack	*ft_parse(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (ac < 2)
		exit(0);
	else if (ac == 2)
		stack_a = ft_parse_args_quoted(av);
	else
		list_args(av, &stack_a);
	return (stack_a);
}
