/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.sort_large_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:19:45 by mbah              #+#    #+#             */
/*   Updated: 2024/12/28 02:45:56 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	init_next_(char *type)
{
	if (ft_strcmp(type, "smaller") == 0)
		return (new_element(-2147483648, -1));
	return (new_element(2147483647, -1));
}

t_stack	find_next_(const t_stack *stack_, t_stack elemnt, char *type)
{
	t_stack	next_;
	int		i;

	next_ = init_next_(type);
	i = -1;
	while (stack_[++i].key != -1)
	{
		if (ft_strcmp(type, "smaller") == 0)
		{
			if (stack_[i].value < elemnt.value)
			{
				if (stack_[i].value >= next_.value)
					next_ = stack_[i];
			}
		}
		else if (ft_strcmp(type, "larger") == 0)
		{
			if (stack_[i].value > elemnt.value)
			{
				if (stack_[i].value <= next_.value)
					next_ = stack_[i];
			}
		}
	}
	return (next_);
}

void	move_and_push_to_b(t_stack *stack_a, t_stack *stack_b, t_stack element)
{
	size_t	stack_size;
	t_stack	next_smaller;

	stack_size = get_stack_size(stack_a);
	optimal_min_move(stack_a, 'a', element, stack_size);
	stack_size = get_stack_size(stack_b);
	if (is_min_or_max(stack_b, element))
		next_smaller = get_max_value(stack_b);
	else
		next_smaller = find_next_(stack_b, element, "smaller");
	optimal_min_move(stack_b, 'b', next_smaller, stack_size);
	push_(stack_a, stack_b, 'b');
}

void	compare_and_push_min_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		cost;
	int		temp;
	t_stack	element;

	temp = calculate_push_cost(stack_a, stack_b, stack_a[0]);
	element = stack_a[0];
	i = -1;
	while (stack_a[++i].key != -1)
	{
		cost = calculate_push_cost(stack_a, stack_b, stack_a[i]);
		if (cost < temp)
		{
			temp = cost;
			element = stack_a[i];
		}
	}
	move_and_push_to_b(stack_a, stack_b, element);
}

int	sort_large_stacks(t_stack *stack_a, t_stack *stack_b)
{
	size_t	size_a;
	t_stack	min;
	int		min_cost_a;
	int		max_cost_a;

	push_(stack_a, stack_b, 'b');
	push_(stack_a, stack_b, 'b');
	min_cost_a = 0;
	max_cost_a = 0;
	while (get_stack_size(stack_a) > 3)
		compare_and_push_min_cost(stack_a, stack_b);
	sort_three_elements(stack_a);
	merge_stacks(stack_a, stack_b, &min_cost_a, &max_cost_a);
	min = get_min_value(stack_a);
	size_a = get_stack_size(stack_a);
	optimal_min_move(stack_a, 'a', min, size_a);
	return (is_stack_sorted(stack_a) && get_stack_size(stack_b) == 0);
}
