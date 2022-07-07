/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:44:54 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:15:28 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_line(char **str)
{
	int		i;
	int		j;
	char	*buffer;

	i = -1;
	buffer = (char *)malloc(5);
	j = read(0, &buffer[++i], 1);
	while (j > 0 && buffer[i] != '\n' && buffer[i] != '\0')
		j = read(0, &buffer[++i], 1);
	buffer[i] = '\0';
	*str = buffer;
	return (j);
}

void	command(t_node **a, t_node **b, char *str)
{
	if (!(ft_strncmp(str, "sa", 3)))
		sa_com(a);
	else if (!(ft_strncmp(str, "sb", 3)))
		sb_com(b);
	else if (!(ft_strncmp(str, "ss", 3)))
		ss_com(a, b);
	else if (!(ft_strncmp(str, "pb", 3)))
		pb_com(a, b);
	else if (!(ft_strncmp(str, "pa", 3)))
		pa_com(b, a);
	else if (!(ft_strncmp(str, "ra", 3)))
		ra_com(a);
	else if (!(ft_strncmp(str, "rb", 3)))
		rb_com(b);
	else if (!(ft_strncmp(str, "rr", 3)))
		rr_com(a, b);
	else if (!(ft_strncmp(str, "rra", 4)))
		rra_com(a);
	else if (!(ft_strncmp(str, "rrb", 4)))
		rrb_com(b);
	else if (!(ft_strncmp(str, "rrr", 4)))
		rrr_com(a, b);
	else
		error();
}

void	checker(t_node **stack_a, int size, int *arr)
{
	t_node	*stack_b;
	char	*str;

	stack_b = NULL;
	assign_index(*stack_a, size, arr);
	while (get_next_line(&str))
	{
		command(stack_a, &stack_b, str);
	}
	if (is_list_sorted(stack_a, size))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(str);
}

int	main(int argc, char **argv)
{
	int		*arr;
	t_node	*stack_a;
	int		size;
	char	**str_arr;

	if (argc > 1)
	{
		arr = arg_handling(argv, &size, &str_arr);
		stack_a = set_list(str_arr);
		leaks_treating(str_arr);
		checker(&stack_a, size, arr);
		node_leaks(stack_a);
		free(arr);
	}
	else
		error();
	return (0);
}
