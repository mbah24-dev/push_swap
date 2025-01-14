/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.stack_op_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:27:31 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 18:58:59 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_(t_stack *stack_, char type)
{
	t_stack	temp;
	int		i;

	i = 0;
	if (stack_[0].key != -1 && stack_[1].key != -1)
	{
		temp.value = stack_[0].value;
		while (stack_[i].key != -1)
		{
			stack_[i].value = stack_[i + 1].value;
			i++;
		}
		stack_[i - 1].value = temp.value;
		reset_keys(stack_);
		if (type == 'a')
			write(1, "ra\n", 3);
		else if (type == 'b')
			write(1, "rb\n", 3);
	}
}

void	rotate_a_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rr\n", 3);
	rotate_(stack_a, 'r');
	rotate_(stack_b, 'r');
}

void	reverse_rotate_(t_stack *stack_, char type)
{
	t_stack	temp;
	size_t	size;

	if (stack_[0].key != -1 && stack_[1].key != -1)
	{
		size = get_stack_size(stack_);
		temp.value = stack_[size - 1].value;
		while (size > 1)
		{
			stack_[size - 1].value = stack_[size - 2].value;
			size--;
		}
		stack_[0].value = temp.value;
		reset_keys(stack_);
		if (type == 'a')
			write(1, "rra\n", 4);
		else if (type == 'b')
			write(1, "rrb\n", 4);
	}
}

void	rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate_(stack_a, 'r');
	reverse_rotate_(stack_b, 'r');
}
