/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.optimal_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:52:41 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 19:00:12 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_final_cost_a_b(t_optimal_move *cost_a_b)
{
	if (cost_a_b[0].is_rotate == cost_a_b[1].is_rotate)
	{
		if (cost_a_b[0].cost < cost_a_b[1].cost)
			return (cost_a_b[1].cost + 1);
		else if (cost_a_b[0].cost > cost_a_b[1].cost)
			return (cost_a_b[0].cost + 1);
		return ((cost_a_b[0].cost + 1));
	}
	return (cost_a_b[0].cost + cost_a_b[1].cost + 1);
}

t_optimal_move	*calc_opt_push_cost(t_stack *stack_a, t_stack *stack_b,
	t_stack elemnt)
{
	t_optimal_move		*cost_a_b;
	t_stack				next_smaller;

	cost_a_b = (t_optimal_move *) malloc(sizeof(t_optimal_move) * 3);
	if (!cost_a_b)
		return (NULL);
	cost_a_b[0] = optimal_move_cost(stack_a, elemnt);
	if (is_min_or_max(stack_b, elemnt))
		cost_a_b[1] = (optimal_move_cost(stack_b, get_max_value(stack_b)));
	else
	{
		next_smaller = find_next_(stack_b, elemnt, "smaller");
		cost_a_b[1] = optimal_move_cost(stack_b, next_smaller);
	}
	return (cost_a_b);
}

void	optimal_move_together(t_stack *stack_a, t_stack *stack_b, int is_rotate,
	int nb)
{
	int	i;

	i = 0;
	if (is_rotate == 1)
	{
		while (i < nb)
		{
			rotate_a_rotate_b(stack_a, stack_b);
			i++;
		}
	}
	else if (is_rotate == 0)
	{
		while (i < nb)
		{
			rra_rrb(stack_a, stack_b);
			i++;
		}
	}
}

void	process_same_op(t_stack *s_a, t_stack *s_b, t_stack elt,
	t_optimal_move *cost_a_b)
{
	t_stack			next_smaller;

	next_smaller = new_element(0, -1);
	if (cost_a_b[0].cost < cost_a_b[1].cost)
	{
		optimal_move_together(s_a, s_b, cost_a_b[0].is_rotate,
			cost_a_b[0].cost);
		if (is_min_or_max(s_b, elt))
			next_smaller = get_max_value(s_b);
		else
			next_smaller = find_next_(s_b, elt, "smaller");
		optimal_min_move(s_b, 'b', next_smaller, get_stack_size(s_b));
	}
	else if (cost_a_b[0].cost > cost_a_b[1].cost)
	{
		optimal_move_together(s_a, s_b, cost_a_b[1].is_rotate,
			cost_a_b[1].cost);
		optimal_min_move(s_a, 'a', elt, get_stack_size(s_a));
	}
	else
		optimal_move_together(s_a, s_b, cost_a_b[0].is_rotate,
			cost_a_b[0].cost);
}

void	optimal_move_and_push_to_b(t_stack *stack_a, t_stack *stack_b,
	t_stack element)
{
	t_stack			next_smaller;
	t_optimal_move	*cost_a_b;

	cost_a_b = calc_opt_push_cost(stack_a, stack_b, element);
	if (cost_a_b[0].is_rotate == cost_a_b[1].is_rotate)
		process_same_op(stack_a, stack_b, element, cost_a_b);
	else
	{
		if (is_min_or_max(stack_b, element))
			next_smaller = get_max_value(stack_b);
		else
			next_smaller = find_next_(stack_b, element, "smaller");
		optimal_min_move(stack_a, 'a', element, get_stack_size(stack_a));
		optimal_min_move(stack_b, 'b', next_smaller, get_stack_size(stack_b));
	}
	push_(stack_a, stack_b, 'b');
}
