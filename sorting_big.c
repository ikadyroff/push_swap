/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:17:00 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:03:07 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	in_a(t_node **stack_a, t_node **stack_b, t_node_param *param)
{
	int	i;
	int	len;

	i = -1;
	len = list_size(stack_b);
	while (++i < len)
	{
		if ((*stack_b)->index == param->min)
			check_min(stack_a, stack_b, param);
		else if ((*stack_b)->index >= param->mid)
		{
			(*stack_b)->flag = param->flag;
			push_a(stack_a, stack_b);
		}
		else
			rotate_b(stack_b);
		if (!(*stack_b))
			break ;
	}
	set_flag_param(param);
}

void	in_b(t_node **stack_a, t_node **stack_b, t_node_param *param)
{
	int	flag_max;

	flag_max = (*stack_a)->flag;
	if ((*stack_a)->flag != 0)
	{
		while ((*stack_a)->flag == flag_max)
			in_b_dop(stack_a, stack_b, param);
		if (*stack_b)
			param->max = max_in_stack(stack_b)->index;
		param->mid = (param->max - param->min) / 2 + param->min;
	}
	else if ((*stack_a)->flag == 0)
	{
		while ((*stack_a)->flag != -1)
			in_b_dop(stack_a, stack_b, param);
		if (*stack_b)
			param->max = max_in_stack(stack_b)->index;
		param->mid = (param->max - param->min) / 2 + param->min;
	}
}

void	big_sorting(t_node **stack_a, t_node **stack_b, int size)
{
	t_node_param	*param;

	param = new_param_node();
	set_param_stack(param, stack_a);
	while (is_list_sorted(stack_a, size) != 1)
	{
		if (!*stack_b && param->flag == 0)
		{
			in_b_first(stack_a, stack_b, param);
		}
		else if (!*stack_b)
			in_b(stack_a, stack_b, param);
		else
			in_a(stack_a, stack_b, param);
	}
	free(param);
}
