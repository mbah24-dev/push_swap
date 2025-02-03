/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:04:36 by mbah              #+#    #+#             */
/*   Updated: 2025/01/15 14:47:40 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_recursively(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		free(str[i]);
		str[i] = (NULL);
	}
	free(str);
	str = (NULL);
}

void	free_all(void *stack_a, void *stack_b)
{
	free(stack_a);
	stack_a = (NULL);
	free(stack_b);
	stack_b = (NULL);
}

int	do_move(t_stack *stack_a, t_stack *stack_b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		do_swap_(stack_a);
	else if (ft_strcmp(op, "sb\n") == 0)
		do_swap_(stack_b);
	else if (ft_strcmp(op, "ss\n") == 0)
		do_swap_a_swap_b(stack_a, stack_b);
	else if (ft_strcmp(op, "pa\n") == 0)
		do_push_(stack_b, stack_a);
	else if (ft_strcmp(op, "pb\n") == 0)
		do_push_(stack_a, stack_b);
	else if (ft_strcmp(op, "ra\n") == 0)
		do_rotate_(stack_a);
	else if (ft_strcmp(op, "rb\n") == 0)
		do_rotate_(stack_b);
	else if (ft_strcmp(op, "rr\n") == 0)
		do_rotate_a_rotate_b(stack_a, stack_b);
	else if (ft_strcmp(op, "rra\n") == 0)
		do_reverse_rotate_(stack_a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		do_reverse_rotate_(stack_b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		do_rra_rrb(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	my_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!do_move(stack_a, stack_b, line))
		{
			write(1, "Error\n", 6);
			free_all(stack_a, stack_b);
			free(line);
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (is_stack_sorted(stack_a) && get_stack_size(stack_b) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**res;
	int		*values;
	int		size;
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void) argc;
	if (argc == 1)
		return (0);
	res = get_values_in_str(argv + 1, ' ');
	an_error_occured(res);
	values = get_final_values(argv + 1, ' ', &size);
	if (!values)
		return (write(1, "Error\n", 6), 1);
	stack_a = fill_stack(values, &stack_b, size);
	if (!stack_a)
		return (write(1, "malloc Stack Error\n", 19), 1);
	if (my_checker(stack_a, stack_b) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_all(stack_a, stack_b);
	return (0);
}
