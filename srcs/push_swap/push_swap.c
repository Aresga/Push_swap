

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = ft_process(argc, argv);
	if (!stack_a || ft_checkdup(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}
	if (!ft_checksorted(stack_a))
		ft_sort(&stack_a);
	ft_free(&stack_a);
	return (0);
}
