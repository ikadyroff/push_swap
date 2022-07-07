/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_ch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:15:04 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:14:31 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra_com(t_node **stack)
{
	t_node	*tmp;
	t_node	*lst;

	if (!(*stack))
		return ;
	lst = *stack;
	tmp = set_last_node(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
}

void	rrb_com(t_node **stack)
{
	t_node	*tmp;
	t_node	*lst;

	if (!(*stack))
		return ;
	lst = *stack;
	tmp = set_last_node(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
}

void	rrr_com(t_node **stack, t_node **stack2)
{
	t_node	*tmp;
	t_node	*lst;

	if (!(*stack2))
		return ;
	lst = *stack;
	tmp = set_last_node(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	lst = *stack2;
	tmp = set_last_node(*stack2);
	while ((*stack2)->next->next)
		*stack = (*stack2)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack2)->next = 0;
	*stack2 = tmp;
}
