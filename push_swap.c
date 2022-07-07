/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:23:18 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:49:44 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

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
		sorting_main(&stack_a, size, arr);
		node_leaks(stack_a);
		free(arr);
	}
	else
		error();
	return (0);
}
