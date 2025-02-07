/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:26:09 by agaga             #+#    #+#             */
/*   Updated: 2025/02/07 16:02:31 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 1)
		exit(0);
	stack_a = ft_init_stack(ac, av);
	if (!stack_a)
	{	
		ft_free(&stack_a);
		ft_error();
	}
	if (!ft_check_sorted(stack_a))
		ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}
