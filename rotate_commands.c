/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:50:37 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:56:07 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = set_last_node(*stack);
	set_last_node(*stack)->next = tmp;
}

void	rotate_a(t_node **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_node **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_a_b(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
