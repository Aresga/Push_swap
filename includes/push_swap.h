/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaga <agaga@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:52:26 by agaga             #+#    #+#             */
/*   Updated: 2025/01/14 15:41:12 by agaga            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef enum e_direction
{
	RA_RB,
	RRA_RRB,
	RA_RRB,
	RRA_RB
}	t_direction;

typedef struct s_cost
{
	int		ra_rb;
	int		rra_rrb;
	int		ra_rrb;
	int		rra_rb;
}	t_cost;

// list utils
void		list_args(char **av, t_stack **stack_a);
void		ft_lstadd_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stack_new(int content);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_lstsize(t_stack *lst);

// checker
t_stack		*ft_init_stack(int ac, char **av);
int			check_args(char **av);
int			ft_checksorted(t_stack *stack_a);
void		ft_error(void);
void		ft_free(t_stack **lst);

// Operations 
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_sa(t_stack **a, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rrr_sub(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);
void		ft_sb(t_stack **b, int j);
void		ft_rrb(t_stack **b, int j);

//Math 
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
int			ft_min_of_four(int a, int b, int c, int d);

//algorithm 
int			ft_index(t_stack *a, int nbr);
int			ft_pos_b(t_stack *stack_b, int nbr_push);
int			ft_pos_a(t_stack *a, int nbr);

t_stack		*ft_parse(int ac, char **av);
t_stack		*ft_parse_args_quoted(char **av);
void		ft_freestr(char **lst);

void		ft_sort_three(t_stack **stack_a);
void		ft_sort(t_stack **stack_a);

// Cost calculations
int			calculate_rotation_ba(t_stack *a, t_stack *b);
int			calculate_cost(t_stack *a, t_stack *b, int c, t_direction dir);
int			calculate_cost_a(t_stack *a, t_stack *b, int c, t_direction dir);
int			rotate_both_up(t_stack **a, t_stack **b, int c, char s);
int			rotate_both_down(t_stack **a, t_stack **b, int c, char s);
int			rotate_a_down_b_up(t_stack **a, t_stack **b, int c, char s);
int			rotate_a_up_b_down(t_stack **a, t_stack **b, int c, char s);

#endif
