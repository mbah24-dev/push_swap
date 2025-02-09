/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:03:47 by mbah              #+#    #+#             */
/*   Updated: 2025/02/09 13:37:50 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_stack
{
	int	value;
	int	key;
};

typedef struct s_stack	t_stack;

/*=========== (s_optimal_move) ===========*/

typedef struct s_optimal_move
{
	int	cost;
	int	is_rotate;
}	t_optimal_move;

t_optimal_move	optimal_move_cost(t_stack *stack_, t_stack val);
int				get_final_cost_a_b(t_optimal_move *cost_a_b);
t_optimal_move	*calc_opt_push_cost(t_stack *stack_a, t_stack *stack_b,
					t_stack elemnt);
void			optimal_move_together(t_stack *stack_a, t_stack *stack_b,
					int is_rotate, int nb);
void			optimal_move_and_push_to_b(t_stack *stack_a, t_stack *stack_b,
					t_stack element);
void			process_same_op(t_stack *s_a, t_stack *s_b, t_stack elt,
					t_optimal_move *cost_a_b);

/*=========== (utils functions) ===========*/

size_t			ft_strlen(char *str);
char			*ft_strdup(char *str);
int				ft_atoi(char *str);
size_t			ft_count_word(char *str, char sp);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
char			**ft_split(char *str, char sp);

/*=========== (parse_argv functions) ===========*/

size_t			number_of_value(char **argv, char sp);
int				deep_copy(char **dst, char **src, int start);
char			**get_values_in_str(char **av, char sp);
int				*get_final_values(char **values, char sp, int *size);

/*=========== (error functions) ===========*/
int				ft_strcmp(char *s1, char *s2);
int				values_is_integer(char **values);
char			*ft_itoa(int n);
void			an_error_occured(char **values);
int				free_fst_return_snd(void *fst, int snd);

/*=========== (init_stack functions) ===========*/
t_stack			new_element(int value, int key);
size_t			get_stack_size(t_stack *stack);
t_stack			*fill_stack(int *values, t_stack **stack_b, int stack_size);

/*=========== (stack_op_swap_push functions) ===========*/
int				is_stack_sorted(t_stack *stack);
void			swap_(t_stack *stack_, char type);
void			swap_a_swap_b(t_stack *stack_a, t_stack *stack_b);
void			push_(t_stack *stack_src, t_stack *stack_dst, char type);

/*=========== (stack_op_rotate functions) ===========*/
void			rotate_(t_stack *stack_, char type);
void			rotate_a_rotate_b(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_(t_stack *stack_, char type);
void			rra_rrb(t_stack *stack_a, t_stack *stack_b);

/*=========== (stack_sort_small functions) ===========*/
void			sort_two_elements(t_stack *stack_a, char type);
void			sort_three_elements(t_stack *stack_a);
void			sort_four_elements(t_stack *stack_a, t_stack *stack_b);
void			sort_five_elements(t_stack *stack_a, t_stack *stack_b);
int				sort_small_stack(t_stack *stack_a, t_stack *stack_b);

/*=========== (stack_sort_small_utils functions) ===========*/
void			reset_keys(t_stack *stack_);
t_stack			get_min_value(t_stack *stack_);
void			move_min_to_top(t_stack *stack_, char type);
void			optimal_min_move(t_stack *stack_, char type, t_stack min,
					int sz);

/*=========== (sort_large_stack et _utils functions) ===========*/
t_stack			get_max_value(const t_stack *stack_);
void			merge_stacks(t_stack *stack_a, t_stack *stack_b);
int				is_min_or_max(t_stack *stack_, t_stack element);
void			compare_and_push_min_cost(t_stack *stack_a, t_stack *stack_b);
int				sort_large_stacks(t_stack *stack_a, t_stack *stack_b);
t_stack			find_next_(const t_stack *stack_, t_stack elemnt, char *type);

/*=========== (push_swap functions) ===========*/
void			free_all(void *stack_a, void *stack_b);
void			free_recursively(char **str);

#endif