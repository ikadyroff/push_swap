/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:59:45 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:56:15 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*node;

	node = *stack;
	tmp = set_last_node(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = node;
	node->prev = tmp;
	tmp->prev = NULL;
	(*stack)->next = NULL;
	*stack = tmp;
}

void	rev_rotate_a(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_node **stack)
{
	rev_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rev_rotate_a_b(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
