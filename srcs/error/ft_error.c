/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:11:38 by agaga             #+#    #+#             */
/*   Updated: 2025/02/03 20:25:07 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Function to print error message
void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
