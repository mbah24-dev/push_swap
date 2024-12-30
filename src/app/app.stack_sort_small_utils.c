/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.stack_sort_small_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 21:37:01 by mbah              #+#    #+#             */
/*   Updated: 2024/12/27 22:42:15 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	reset_keys(t_stack *stack_)
{
	size_t	i;

	i = 0;
	while (i < get_stack_size(stack_))
	{
		stack_[i].key = i;
		i++;
	}
	stack_[i].key = -1;
}

void	optimal_min_move(t_stack *stack_, char type, t_stack min, int sz)
{
	int	nb_rotate;
	int	nb_rev_rotate;

	nb_rotate = min.key;
	nb_rev_rotate = stack_[sz - 1].key - min.key + 1;
	if (nb_rotate <= nb_rev_rotate)
	{
		while (stack_[0].value != min.value)
			rotate_(stack_, type);
	}
	else
	{
		while (stack_[0].value != min.value)
			reverse_rotate_(stack_, type);
	}
}

void	move_min_to_top(t_stack *stack_, char type)
{
	t_stack	min;
	size_t	stack_size;

	stack_size = get_stack_size(stack_);
	if (stack_size >= 3)
	{
		min = get_min_value(stack_);
		if (min.key == 1)
			rotate_(stack_, type);
		else if (min.key >= 2)
			optimal_min_move(stack_, type, min, stack_size);
	}
	else if (stack_size == 2)
		swap_(stack_, type);
}

t_stack	get_min_value(t_stack *stack_)
{
	int		i;
	t_stack	min_value;

	i = 1;
	min_value = stack_[0];
	while (stack_[i].key != -1)
	{
		if (min_value.value > stack_[i].value)
			min_value = stack_[i];
		i++;
	}
	return (min_value);
}
