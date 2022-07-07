/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:50:11 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:56:11 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **a_node, t_node **b_node)
{
	t_node	*a_tmp;
	t_node	*b_tmp;

	if (!(*b_node)->next)
	{
		a_tmp = (*a_node);
		b_tmp = (*b_node)->next;
		*a_node = *b_node;
		(*a_node)->next = a_tmp;
		a_tmp->prev = (*a_node);
		*b_node = b_tmp;
	}
	else
	{
		a_tmp = (*a_node);
		b_tmp = (*b_node)->next;
		*a_node = *b_node;
		(*a_node)->next = a_tmp;
		a_tmp->prev = (*a_node);
		*b_node = b_tmp;
		(*b_node)->prev = NULL;
	}
	write(1, "pa\n", 3);
}

void	push_b(t_node **a_node, t_node **b_node)
{
	t_node	*a_tmp;
	t_node	*b_tmp;

	if (!*b_node)
	{
		a_tmp = (*a_node)->next;
		*b_node = *a_node;
		*a_node = a_tmp;
		(*a_node)->prev = NULL;
		(*b_node)->next = NULL;
	}
	else
	{
		a_tmp = (*a_node)->next;
		b_tmp = (*b_node);
		*b_node = *a_node;
		(*b_node)->next = b_tmp;
		b_tmp->prev = (*b_node);
		*a_node = a_tmp;
		(*a_node)->prev = NULL;
	}
	write(1, "pb\n", 3);
}
