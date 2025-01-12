/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:43:30 by agaga             #+#    #+#             */
/*   Updated: 2025/01/12 21:05:45 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_init_stack(int ac, char **av)
{
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	if (ac < 2)
		exit(0);
	if (!check_args(av))
		ft_error();
	if (ac == 2)
		a = ft_parse_args_quoted(av);
	else
	{
		while (i < ac)
		{
			ft_add_back(&a, ft_stack_new(ft_atoi(av[i])));
			i++;
		}
	}
	return (a);
}
