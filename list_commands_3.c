/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:53:43 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:27:37 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*max_in_stack(t_node **stack)
{
	t_node	*max_list;
	t_node	*tmp_list;

	max_list = *stack;
	tmp_list = *stack;
	while (tmp_list)
	{
		if (max_list->num < tmp_list->num)
			max_list = tmp_list;
		tmp_list = tmp_list->next;
	}
	return (max_list);
}

t_node_param	*new_param_node(void)
{
	t_node_param	*new_node;

	new_node = malloc(sizeof(t_node_param));
	if (!new_node)
		return (NULL);
	new_node->min = 0;
	new_node->max = 0;
	new_node->mid = 0;
	new_node->flag = 0;
	return (new_node);
}

void	set_param_stack(t_node_param *new, t_node **stack)
{
	if (!(stack))
		return ;
	new->min = min_in_stack(stack)->index;
	new->max = max_in_stack(stack)->index;
	new->mid = new->max / 2 + new->min;
}

void	set_flag_param(t_node_param *param)
{
	param->max = param->mid;
	param->mid = (param->max - param->min) / 2 + param->min;
	param->flag++;
}

t_node	*last_in_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	if (!tmp)
		return (tmp);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
