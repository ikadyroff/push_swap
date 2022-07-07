/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands_ch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:15:07 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:14:35 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra_com(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = set_last_node(*stack);
	set_last_node(*stack)->next = tmp;
}

void	rb_com(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = set_last_node(*stack);
	set_last_node(*stack)->next = tmp;
}

void	rr_com(t_node **stack, t_node **stack2)
{
	t_node	*tmp;

	if (!(*stack2))
		return ;
	tmp = *stack;
	*stack = tmp->next;
	(*stack)->prev = 0;
	tmp->next = 0;
	tmp->prev = set_last_node(*stack);
	set_last_node(*stack)->next = tmp;
	tmp = *stack2;
	*stack2 = tmp->next;
	(*stack2)->prev = 0;
	tmp->next = 0;
	tmp->prev = set_last_node(*stack2);
	set_last_node(*stack2)->next = tmp;
}
