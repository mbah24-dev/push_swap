/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.parse_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:01:00 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 19:00:02 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	number_of_value(char **argv, char sp)
{
	size_t	number;
	int		i;

	number = 0;
	i = -1;
	while (argv && argv[++i])
		number = number + ft_count_word(*(argv + i), sp);
	return (number);
}

int	deep_copy(char **dst, char **src, int start)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i + start] = ft_strdup(src[i]);
	return (i);
}

char	**get_values_in_str(char **av, char sp)
{
	char	**values;
	char	**temp;
	int		i;
	int		j;
	size_t	nb_values;

	i = -1;
	j = 0;
	nb_values = number_of_value(av, sp);
	values = malloc(sizeof(char *) * (nb_values + 1));
	if (!values)
		return (NULL);
	while (av && av[++i])
	{
		temp = ft_split(av[i], sp);
		j = j + deep_copy(values, temp, j);
		free_recursively(temp);
	}
	values[nb_values] = (NULL);
	return (values);
}

int	*get_final_values(char **values, char sp, int *size)
{
	int		*res;
	int		i;
	char	**temp;

	i = 0;
	temp = get_values_in_str(values, sp);
	if (!temp)
		return (NULL);
	while (temp && temp[i])
		i++;
	res = (int *) malloc(sizeof(int) * (i));
	*size = i;
	if (!res)
		return (free_recursively(temp), NULL);
	i = -1;
	while (temp[++i])
		res[i] = (ft_atoi(temp[i]));
	return (free_recursively(temp), res);
}
