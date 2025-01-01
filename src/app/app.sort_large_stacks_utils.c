/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.sort_large_stacks_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:03:42 by mbah              #+#    #+#             */
/*   Updated: 2024/12/28 02:44:44 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

int	move_to_top_cost(t_stack *stack_, t_stack val)
{
	int		nb_rotate;
	int		nb_rev_rotate;
	size_t	stack_size;

	stack_size = get_stack_size(stack_);
	nb_rotate = val.key;
	nb_rev_rotate = stack_[stack_size - 1].key - val.key + 1;
	if (nb_rotate <= nb_rev_rotate)
		return (nb_rotate);
	return (nb_rev_rotate);
}

int	calculate_push_cost(t_stack *stack_a, t_stack *stack_b, t_stack elemnt)
{
	int		cost_a;
	int		cost_b;
	t_stack	next_smaller;

	cost_a = move_to_top_cost(stack_a, elemnt);
	if (is_min_or_max(stack_b, elemnt))
		cost_b = (move_to_top_cost(stack_b, get_max_value(stack_b)));
	else
	{
		next_smaller = find_next_(stack_b, elemnt, "smaller");
		cost_b = move_to_top_cost(stack_b, next_smaller);
	}
	return (cost_a + cost_b + 1);
}

void	merge_stacks(t_stack *stack_a, t_stack *stack_b,
	int *min_cost, int *max_cost)
{
	t_stack	next_larger;
	size_t	size_a;

	next_larger = new_element(2147483647, -1);
	while (stack_b[0].key != -1)
	{
		size_a = get_stack_size(stack_a);
		if (is_min_or_max(stack_a, stack_b[0]))
		{
			*min_cost = move_to_top_cost(stack_a, get_min_value(stack_a));
			*max_cost = move_to_top_cost(stack_a, get_max_value(stack_a));
			if (*max_cost <= *min_cost)
				optimal_min_move(stack_a, 'a', get_max_value(stack_a), size_a);
			else
				optimal_min_move(stack_a, 'a', get_min_value(stack_a), size_a);
		}
		else
		{
			next_larger = find_next_(stack_a, stack_b[0], "larger");
			optimal_min_move(stack_a, 'a', next_larger, size_a);
		}
		push_(stack_b, stack_a, 'a');
	}
}
