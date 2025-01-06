/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.sort_large_stacks_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:03:42 by mbah              #+#    #+#             */
/*   Updated: 2025/01/06 01:21:00 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_optimal_move	optimal_move_cost(t_stack *stack_, t_stack val)
{
	int				nb_rotate;
	int				nb_rev_rotate;
	size_t			stack_size;
	t_optimal_move	opt_move;

	stack_size = get_stack_size(stack_);
	nb_rotate = val.key;
	nb_rev_rotate = stack_[stack_size - 1].key - val.key + 1;
	if (nb_rotate <= nb_rev_rotate)
	{
		if (nb_rotate == 0)
			opt_move.is_rotate = 3;
		else
			opt_move.is_rotate = 1;
		opt_move.cost = nb_rotate;
		return (opt_move);
	}
	opt_move.cost = nb_rev_rotate;
	opt_move.is_rotate = 0;
	return (opt_move);
}

t_stack	get_max_value(const t_stack *stack_)
{
	t_stack	max;
	int		i;

	max = stack_[0];
	i = -1;
	while (stack_[++i].key != -1)
	{
		if (max.value < stack_[i].value)
			max = stack_[i];
	}
	return (max);
}

int	is_min_or_max(t_stack *stack_, t_stack element)
{
	t_stack	min;
	t_stack	max;

	min = get_min_value(stack_);
	max = get_max_value(stack_);
	if (element.value > max.value || element.value < min.value)
		return (1);
	return (0);
}

void	merge_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	next_larger;
	size_t	size_a;

	next_larger = new_element(2147483647, -1);
	while (stack_b[0].key != -1)
	{
		size_a = get_stack_size(stack_a);
		if (is_min_or_max(stack_a, stack_b[0]))
			optimal_min_move(stack_a, 'a', get_min_value(stack_a), size_a);
		else
		{
			next_larger = find_next_(stack_a, stack_b[0], "larger");
			optimal_min_move(stack_a, 'a', next_larger, size_a);
		}
		push_(stack_b, stack_a, 'a');
	}
}
