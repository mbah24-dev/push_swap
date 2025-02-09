/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.stack_op_swap_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:51:14 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 18:59:00 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	if (get_stack_size(stack) <= 1)
		return (1);
	while (stack[i].key != -1 && stack[i + 1].key != -1)
	{
		if (stack[i].value > stack[i + 1].value)
			return (0);
		i++;
	}
	return (1);
}

void	swap_(t_stack *stack_, char type)
{
	t_stack	temp;

	if (get_stack_size(stack_) >= 2)
	{
		temp = stack_[0];
		stack_[0].value = stack_[1].value;
		stack_[1].value = temp.value;
		if (type == 'a')
			write(1, "sa\n", 3);
		else if (type == 'b')
			write(1, "sb\n", 3);
	}
}

void	swap_a_swap_b(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "sa\n", 3);
	swap_(stack_a, 'a');
	write(1, "sb\n", 3);
	swap_(stack_b, 'b');
}

void	push_(t_stack *stack_src, t_stack *stack_dst, char type)
{
	size_t	dst_size;
	int		i;

	if (stack_src[0].key != -1)
	{
		dst_size = get_stack_size(stack_dst) + 1;
		while (dst_size != 0)
		{
			stack_dst[dst_size] = stack_dst[dst_size - 1];
			dst_size--;
		}
		stack_dst[0] = stack_src[0];
		i = -1;
		while (stack_src[++i].key != -1)
			stack_src[i].value = stack_src[i + 1].value;
		stack_src[i - 1] = stack_src[i];
		reset_keys(stack_dst);
		reset_keys(stack_src);
		if (type == 'a')
			write(1, "pa\n", 3);
		else if (type == 'b')
			write(1, "pb\n", 3);
	}
}
