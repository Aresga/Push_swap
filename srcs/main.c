/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:26:09 by agaga             #+#    #+#             */
/*   Updated: 2025/01/18 14:56:05 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	if (ac == 1)
		exit(0);
	// if (!check_args(av))
	// 	ft_error();
	stack_a = ft_init_stack(ac, av);
	if (!stack_a)
		ft_error();
	if (!ft_check_sorted(stack_a))
		ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}
