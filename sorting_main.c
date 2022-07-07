/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:37:22 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:35:14 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_b(t_node **stack_a, t_node **stack_b)
{
	int	pos;

	while (list_size(stack_a) > 3)
	{
		pos = check_position_list(stack_a, min_in_stack(stack_a));
		if (pos == 0)
			push_b(stack_a, stack_b);
		else if (pos < (list_size(stack_a) / 2 + 1))
			rotate_a(stack_a);
		else
			rev_rotate_a(stack_a);
	}
}

void	sorting_2(t_node **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		swap_a(stack_a);
}

void	sorting_3(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->num;
	b = (*stack_a)->next->num;
	c = (*stack_a)->next->next->num;
	if (a > b && b > c)
	{
		swap_a(stack_a);
		rev_rotate_a(stack_a);
	}
	else if (a < b && b > c && c < a)
		rev_rotate_a(stack_a);
	else if (a < b && b > c && c > a)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a > b && b < c && c > a)
		swap_a(stack_a);
	else if (a > b && b < c && c < a)
		rotate_a(stack_a);
}

void	sorting_5(t_node **stack_a, t_node **stack_b)
{
	min_b(stack_a, stack_b);
	sorting_3(stack_a);
	while (list_size(stack_b) > 0)
		push_a(stack_a, stack_b);
}

void	sorting_main(t_node **stack_a, int size, int *arr)
{
	t_node	*stack_b;

	stack_b = NULL;
	assign_index(*stack_a, size, arr);
	if (size == 2)
		sorting_2(stack_a);
	else if (size == 3)
		sorting_3(stack_a);
	else if (size > 3 && size < 6)
		sorting_5(stack_a, &stack_b);
	else if (size > 5)
		big_sorting(stack_a, &stack_b, size);
	else
		return ;
}
