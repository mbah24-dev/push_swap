/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.sort_small_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 23:00:09 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 18:58:58 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_elements(t_stack *stack_a, char type)
{
	if (!is_stack_sorted(stack_a))
		swap_(stack_a, type);
}

void	sort_three_elements(t_stack *stack_a)
{
	if (!is_stack_sorted(stack_a))
	{
		if (get_min_value(stack_a).key == 1)
		{
			if (stack_a[0].value > stack_a[2].value)
				rotate_(stack_a, 'a');
			else
				sort_two_elements(stack_a, 'a');
		}
		else if ((stack_a[0].value < stack_a[1].value))
		{
			reverse_rotate_(stack_a, 'a');
			sort_two_elements(stack_a, 'a');
		}
		else if ((stack_a[0].value > stack_a[1].value))
		{
			sort_two_elements(stack_a, 'a');
			if (!is_stack_sorted(stack_a))
				reverse_rotate_(stack_a, 'a');
			sort_two_elements(stack_a, 'a');
		}
	}
}

void	sort_four_elements(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_stack_sorted(stack_a))
	{
		move_min_to_top(stack_a, 'a');
		if (!is_stack_sorted(stack_a))
		{
			push_(stack_a, stack_b, 'b');
			reset_keys(stack_b);
			sort_three_elements(stack_a);
			push_(stack_b, stack_a, 'a');
			reset_keys(stack_a);
		}
	}
}

void	sort_five_elements(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_stack_sorted(stack_a))
	{
		move_min_to_top(stack_a, 'a');
		if (!is_stack_sorted(stack_a))
		{
			push_(stack_a, stack_b, 'b');
			reset_keys(stack_b);
			sort_four_elements(stack_a, stack_b);
			push_(stack_b, stack_a, 'a');
			reset_keys(stack_a);
		}
	}
}

int	sort_small_stack(t_stack *stack_a, t_stack *stack_b)
{
	size_t	stack_sz;

	stack_sz = get_stack_size(stack_a);
	if (stack_sz > 5)
		return (0);
	if (stack_sz == 5)
		sort_five_elements(stack_a, stack_b);
	if (stack_sz == 4)
		sort_four_elements(stack_a, stack_b);
	if (stack_sz <= 3)
		sort_three_elements(stack_a);
	return (is_stack_sorted(stack_a));
}
