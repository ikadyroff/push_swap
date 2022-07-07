/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:39:31 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:30:18 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_min_b(t_node **a, t_node **b, t_node_param *param)
{
	if ((*a)->index == param->min)
	{
		rotate_a(a);
		param->min++;
		check_min(a, b, param);
	}
	else if (list_size(b) > 0 && (*b)->index == param->min)
	{
		(*b)->flag = -1;
		push_a(a, b);
		rotate_a(a);
		param->min++;
		check_min(a, b, param);
	}
	else if ((*a)->next->index == param->min && list_size(b) > 1
		&& (*b)->next->index == param->min + 1)
	{
		swap_a_and_b(a, b);
		(*a)->flag = -1;
		rotate_a(a);
		param->min++;
		check_min(a, b, param);
	}
}

void	check_min(t_node **a, t_node **b, t_node_param *param)
{
	if ((*a)->index == param->min)
		check_min_b(a, b, param);
	else if (list_size(b) > 0 && (*b)->index == param->min)
		check_min_b(a, b, param);
	else if ((*a)->next->index == param->min && list_size(b) > 1
		&& (*b)->next->index == param->min + 1)
		check_min_b(a, b, param);
	else if ((*a)->next->index == param->min)
	{
		swap_a(a);
		(*a)->flag = -1;
		rotate_a(a);
		param->min++;
		check_min(a, b, param);
	}
	else if (list_size(b) > 2 && last_in_stack(b)->index == param->min)
	{
		rev_rotate_b(b);
		push_a(a, b);
		(*a)->flag = -1;
		rotate_a(a);
		param->min++;
		check_min(a, b, param);
	}
}

void	in_b_dop(t_node **a, t_node **b, t_node_param *param)
{
	if ((*a)->index == param->min)
	{
		(*a)->flag = -1;
		rotate_a(a);
		param->min++;
		check_min(a, b, param);
	}
	else
	{
		push_b(a, b);
		check_min(a, b, param);
	}
}

void	in_rr(t_node **a, t_node **b, t_node_param *param)
{
	if (list_size(b) > 1 && (*b)->index < (param->mid / 2))
		rotate_a_b(a, b);
	else
		rotate_a(a);
}

void	in_b_first(t_node **a, t_node **b, t_node_param *param)
{
	int	i;
	int	len;

	i = -1;
	len = list_size(a);
	while (++i < len)
	{
		if ((*a)->index <= param->mid)
		{
			push_b(a, b);
		}
		else
			in_rr(a, b, param);
	}
	set_flag_param(param);
}
