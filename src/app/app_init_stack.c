/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.init_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:12:33 by mbah              #+#    #+#             */
/*   Updated: 2025/02/09 13:28:22 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack[size].key != -1)
		size++;
	return (size);
}

t_stack	new_element(int value, int key)
{
	t_stack	element;

	element.value = value;
	element.key = key;
	return (element);
}

t_stack	*fill_stack(int *values, t_stack **stack_b, int stack_size)
{
	t_stack	*stack_a;
	int		i;

	i = 0;
	stack_a = (t_stack *) malloc(sizeof(t_stack) * (stack_size + 2));
	*stack_b = (t_stack *) malloc(sizeof(t_stack) * (stack_size + 2));
	if (!stack_a || !(*stack_b))
	{
		free(values);
		free_all(stack_a, *stack_b);
		return (NULL);
	}
	while (i < stack_size)
	{
		stack_a[i] = new_element(values[i], i);
		(*stack_b)[i] = new_element(0, -1);
		i++;
	}
	stack_a[i] = new_element(0, -1);
	(*stack_b)[i] = new_element(0, -1);
	free(values);
	return (stack_a);
}
