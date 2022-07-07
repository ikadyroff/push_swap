/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands_ch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 12:15:00 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:15:07 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb_com(t_node **a, t_node **b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	if (!*b)
	{
		tmp_a = (*a)->next;
		*b = *a;
		*a = tmp_a;
		(*a)->prev = 0;
		(*b)->next = 0;
	}
	else
	{
		tmp_b = (*b);
		tmp_a = (*a)->next;
		*b = *a;
		(*b)->next = tmp_b;
		tmp_b->prev = (*b);
		*a = tmp_a;
		(*a)->prev = 0;
	}
}

void	pa_com(t_node **b, t_node **a)
{
	t_node	*tmp_b;
	t_node	*tmp_a;

	if (!(*b)->next)
	{
		tmp_a = (*a);
		tmp_b = (*b)->next;
		*a = *b;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
		*b = tmp_b;
	}
	else
	{
		tmp_a = (*a);
		tmp_b = (*b)->next;
		*a = *b;
		(*a)->next = tmp_a;
		tmp_a->prev = (*a);
		*b = tmp_b;
		(*b)->prev = 0;
	}
}
