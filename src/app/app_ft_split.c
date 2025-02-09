/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:21:48 by mbah              #+#    #+#             */
/*   Updated: 2025/02/09 13:30:23 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_free_all(char **str, int *i)
{
	while (*i >= 0)
	{
		free(str[*i]);
		str[*i] = (NULL);
		*i = *i - 1;
	}
	free(str);
	str = (NULL);
	return (NULL);
}

static size_t	ft_wordsize(char *str, char sp)
{
	size_t	number;

	number = 0;
	while (str[number] && str[number] != sp)
		number = number + 1;
	return (number);
}

char	**ft_split(char *str, char sp)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char **) malloc(sizeof(char *) * (ft_count_word(str, sp) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] != sp)
		{
			res[j] = malloc(sizeof(char) * (ft_wordsize(str + i, sp) + 1));
			if (!res[j])
				return (ft_free_all(res, &j));
			ft_strlcpy(res[j], str + i, ft_wordsize(str + i, sp) + 1);
			j = j + 1;
			i = i + ft_wordsize(str + i, sp);
		}
		else
			i = i + 1;
	}
	res[j] = (NULL);
	return (res);
}
