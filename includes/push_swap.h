/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:03:47 by mbah              #+#    #+#             */
/*   Updated: 2024/12/20 23:29:45 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

struct	s_stack
{
	int	value;
	int	key;
};

typedef struct s_stack	t_stack;

/*=========== (utils functions) ===========*/

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_atoi(char *str);
size_t	ft_count_word(char *str, char sp);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	**ft_split(char *str, char sp);

/*=========== (parse_argv functions) ===========*/

size_t	number_of_value(char **argv, char sp);
int		deep_copy(char **dst, char **src, int start);
char	**get_values_in_str(char **av, char sp);
int		*get_final_values(char **values, char sp, int *size);

/*=========== (error functions) ===========*/
int		ft_strcmp(char *s1, char *s2);
int		values_is_integer(char **values);
char	*ft_itoa(int n);
int		an_error_occured(char **values);

/*=========== (init_stack functions) ===========*/
t_stack	new_element(int value, int key);
size_t	get_stack_size(t_stack *stack);
t_stack	*fill_stack(int *values, t_stack **stack_b, int stack_size);
void	stack_status(t_stack *stack);

/*=========== (stack_op_swap_push functions) ===========*/
int		is_stack_sorted(t_stack *stack);
void	swap_(t_stack *stack_, char type);
void	swap_a_swap_b(t_stack *stack_a, t_stack *stack_b);
void	push_(t_stack *stack_src, t_stack *stack_dst, char type);

/*=========== (stack_op_rotate functions) ===========*/
void	rotate_(t_stack *stack_, char type);
void	rotate_a_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_(t_stack *stack_, char type);
void	rra_rrb(t_stack *stack_a, t_stack *stack_b);

/*=========== (stack_sort_small functions) ===========*/
void	sort_two_elements(t_stack *stack_a, char type);
void	sort_three_elements(t_stack *stack_a);
void	sort_four_elements(t_stack *stack_a, t_stack *stack_b);

/*=========== (stack_sort_small_utils functions) ===========*/
t_stack	get_max_value(t_stack *stack_);
void	move_max_to_top(t_stack *stack_, char type);

#endif