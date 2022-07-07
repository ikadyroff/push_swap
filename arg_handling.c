/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:25:39 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/13 20:11:24 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	error();
}

char	**get_array(char **argv)
{
	int		i;
	char	*str;
	char	**arr;
	char	*tmp;

	str = ft_strdup(argv[1]);
	i = 2;
	while (argv[i])
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, argv[i]);
		free(tmp);
		i++;
	}
	arr = ft_split(str, ' ');
	free(str);
	return (arr);
}

void	is_double(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				free_arr(arr);
			j++;
		}
	}
}

void	arr_checking(char **arr)
{
	int			i;
	int			j;

	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '-')
				j++;
			if (ft_isdigit(arr[i][j]) == 0)
				free_arr(arr);
			j++;
		}
		if (ft_atoi(arr[i]) < -2147483648 || ft_atoi(arr[i]) > 2147483647)
			free_arr(arr);
	}
	is_double(arr);
}
