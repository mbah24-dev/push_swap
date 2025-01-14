/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:57:24 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 18:58:06 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
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
	stack_a = fill_stack(values, &stack_b, size);
	free(values);
	values = (NULL);
	if (get_stack_size(stack_a) <= 5)
		sort_small_stack(stack_a, stack_b);
	else
		sort_large_stacks(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
