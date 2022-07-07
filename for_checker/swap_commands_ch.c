/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:15:10 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:14:37 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa_com(t_node	**stack)
{
	t_node	*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = tmp;
}

void	sb_com(t_node	**stack)
{
	t_node	*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack)->next->next;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->next = (*stack);
	*stack = (*stack)->next;
	(*stack)->prev = 0;
	(*stack)->next->next = tmp;
}

void	ss_com(t_node	**stack1, t_node **stack2)
{
	t_node	*tmp;

	if (!(*stack2))
		return ;
	tmp = (*stack1)->next->next;
	(*stack1)->prev = (*stack1)->next;
	(*stack1)->next->next = (*stack1);
	*stack1 = (*stack1)->next;
	(*stack1)->prev = 0;
	(*stack1)->next->next = tmp;
	tmp = (*stack2)->next->next;
	(*stack2)->prev = (*stack2)->next;
	(*stack2)->next->next = (*stack2);
	*stack2 = (*stack2)->next;
	(*stack2)->prev = 0;
	(*stack2)->next->next = tmp;
}
