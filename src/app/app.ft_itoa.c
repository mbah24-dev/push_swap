/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.ft_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:45:44 by mbah              #+#    #+#             */
/*   Updated: 2025/01/14 19:00:42 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}

static int	ft_len(int number)
{
	int	len;

	len = 1;
	if (number < 0)
		len++;
	while (number / 10 != 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

static void	ft_itoa_recursive(long number, char *res, int *idx)
{
	if (number >= 10)
	{
		ft_itoa_recursive(number / 10, res, idx);
		ft_itoa_recursive(number % 10, res, idx);
	}
	else
	{
		res[*idx] = number + 48;
		(*idx) += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	number;

	i = 0;
	number = n;
	res = (char *) malloc(sizeof(char) * (ft_len(number) + 1));
	if (!res)
		return (NULL);
	if (number < 0)
	{
		res[i] = '-';
		i++;
		number *= -1 ;
	}
	ft_itoa_recursive(number, res, &i);
	res[i] = '\0';
	return (res);
}
