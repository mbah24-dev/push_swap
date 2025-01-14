/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.checker_push_op_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:15:02 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 23:53:22 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_swap_(t_stack *stack_)
{
	t_stack	temp;

	if (get_stack_size(stack_) >= 2)
	{
		temp = stack_[0];
		stack_[0].value = stack_[1].value;
		stack_[1].value = temp.value;
	}
}

void	do_swap_a_swap_b(t_stack *stack_a, t_stack *stack_b)
{
	do_swap_(stack_a);
	do_swap_(stack_b);
}

void	do_push_(t_stack *stack_src, t_stack *stack_dst)
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
	}
}
