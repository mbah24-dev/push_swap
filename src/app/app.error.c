/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 22:21:36 by mbah              #+#    #+#             */
/*   Updated: 2024/12/25 19:56:18 by mbah             ###   ########.fr       */
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

	i = 0;
	while (values[i])
	{
		if (values[i][0] != '+')
		{
			if (ft_strcmp(values[i], ft_itoa(ft_atoi(values[i]))) != 0)
				return (0);
		}
		else
		{
			if (ft_strcmp(values[i] + 1, ft_itoa(ft_atoi(values[i]))) != 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int	an_error_occured(char **values)
{
	if (has_value_duplicates(values) || !values_is_integer(values))
		return (1);
	return (0);
}
