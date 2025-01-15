/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbah <mbah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:20:43 by mbah              #+#    #+#             */
/*   Updated: 2025/01/15 14:45:41 by mbah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line_bonus.h"

void	do_rotate_(t_stack *stack_);
void	do_rotate_a_rotate_b(t_stack *stack_a, t_stack *stack_b);
void	do_reverse_rotate_(t_stack *stack_);
void	do_rra_rrb(t_stack *stack_a, t_stack *stack_b);
void	do_swap_(t_stack *stack_);
void	do_swap_a_swap_b(t_stack *stack_a, t_stack *stack_b);
void	do_push_(t_stack *stack_src, t_stack *stack_dst);
int		do_move(t_stack *stack_a, t_stack *stack_b, char *op);
int		my_checker(t_stack *stack_a, t_stack *stack_b);

#endif