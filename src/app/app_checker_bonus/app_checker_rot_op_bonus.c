/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.checker_rot_op_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:17:10 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 23:53:31 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_rotate_(t_stack *stack_)
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
	}
}

void	do_rotate_a_rotate_b(t_stack *stack_a, t_stack *stack_b)
{
	do_rotate_(stack_a);
	do_rotate_(stack_b);
}

void	do_reverse_rotate_(t_stack *stack_)
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
	}
}

void	do_rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	do_reverse_rotate_(stack_a);
	do_reverse_rotate_(stack_b);
}
