/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:21:36 by mbah              #+#    #+#             */
/*   Updated: 2025/02/09 13:39:05 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_fst_return_snd(void *fst, int snd)
{
	free(fst);
	fst = NULL;
	return (snd);
}

int	has_value_duplicates(char **values)
{
	int	i;
	int	j;

	i = 0;
	if (values)
	{
		while (values[i])
		{
			j = i + 1;
			while (values[j])
			{
				if (ft_strcmp(values[i], values[j]) == 0)
					return (1);
				j = j + 1;
			}
			i = i + 1;
		}
		return (0);
	}
	return (1);
}

int	values_is_integer(char **values)
{
	int		i;
	char	*itoa_return;

	i = 0;
	if (values)
	{
		while (values[i])
		{
			itoa_return = ft_itoa(ft_atoi(values[i]));
			if (values[i][0] != '+')
			{
				if (ft_strcmp(values[i], itoa_return) != 0)
				{
					free(itoa_return);
					return (0);
				}
				free(itoa_return);
			}
			else
				return (free_fst_return_snd(itoa_return, 0));
			i++;
		}
		return (1);
	}
	return (0);
}

void	an_error_occured(char **values)
{
	if (!values)
	{
		write(2, "Malloc Error\n", 13);
		exit(-1);
	}
	if (has_value_duplicates(values) || !values_is_integer(values))
	{
		free_recursively(values);
		write(2, "Error\n", 6);
		exit(1);
	}
	free_recursively(values);
	values = (NULL);
}
