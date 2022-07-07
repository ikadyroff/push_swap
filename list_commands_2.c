/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:33:18 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:34:04 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *stack_a, int size, int *arr)
{
	int		i;
	t_node	*list;

	list = stack_a;
	while (list)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == list->num)
				list->index = i;
			i++;
		}
		list = list->next;
	}
}

int	list_size(t_node **stack)
{
	t_node	*list;
	int		size;

	size = 0;
	list = *stack;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

int	is_list_sorted(t_node **stack, int size)
{
	t_node	*list;

	list = *stack;
	if (list_size(stack) != size)
		return (0);
	while (list -> next)
	{
		if (list->index > list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

t_node	*min_in_stack(t_node **stack)
{
	t_node	*min;
	t_node	*tmp;

	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (min->num > tmp->num)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

int	check_position_list(t_node **stack, t_node *list)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp != list)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
