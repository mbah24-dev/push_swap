/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:21:36 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 18:45:31 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	has_value_duplicates(char **values)
{
	int	i;
	int	j;

	i = 0;
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

/* evite le signe + a la ligne 49 */
int	values_is_integer(char **values)
{
	int		i;
	char	*itoa_return;

	i = 0;
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
		}
		else
			return (free(itoa_return), 0);
		i++;
	}
	return (free(itoa_return), 1);
}

void	an_error_occured(char **values)
{
	if (has_value_duplicates(values) || !values_is_integer(values))
	{
		free_recursively(values);
		write(1, "Error\n", 6);
		exit(1);
	}
	free_recursively(values);
	values = (NULL);
}
