/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:15:44 by mbah              #+#    #+#             */
/*   Updated: 2024/12/25 19:54:15 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i = i + 1;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

size_t	ft_count_word(char *str, char sp)
{
	size_t	number;
	int		i;

	number = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != sp)
		{
			number = number + 1;
			while (str[i] && str[i] != sp)
				i++;
		}
		else
			i++;
	}
	return (number);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
