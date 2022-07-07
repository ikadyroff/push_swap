/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:49:47 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:11:43 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	error(void)
{
	ft_putstr_fd("Error, wrong arguments!\nEx: './push_swap 2 1 3 6 5 8'\n", 2);
	exit(0);
}

void	leaks_treating(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	*bubble_sort(char **arr, int len)
{
	int	*sorted_arr;
	int	i;
	int	j;
	int	tmp;

	sorted_arr = malloc(sizeof(int) * len);
	i = -1;
	while (arr[++i])
		sorted_arr[i] = ft_atoi(arr[i]);
	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (sorted_arr[j] > sorted_arr[j + 1])
			{
				tmp = sorted_arr[j];
				sorted_arr[j] = sorted_arr[j + 1];
				sorted_arr[j + 1] = tmp;
			}
		}
	}
	return (sorted_arr);
}

t_node	*set_list(char **arr)
{
	t_node	*stack;
	int		i;	

	stack = 0;
	i = 0;
	while (arr[i])
	{
		add_node_back(&stack, ft_lstnew(ft_atoi(arr[i])));
		i++;
	}
	return (stack);
}

int	*arg_handling(char **argv, int *size, char ***str_arr)
{
	char	**arr;
	int		*sorted_arr;
	int		len;

	arr = get_array(argv);
	arr_checking(arr);
	len = 0;
	while (arr[len])
		len++;
	sorted_arr = bubble_sort(arr, len);
	*size = len;
	*str_arr = arr;
	return (sorted_arr);
}
