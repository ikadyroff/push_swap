/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:23:31 by wlouveni          #+#    #+#             */
/*   Updated: 2022/02/28 17:06:33 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoi(const char *str)
{
	unsigned long long	digit;
	int					znak;

	digit = 0;
	znak = 1;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r' || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			znak = -1;
	}
	while (*str && *str > 47 && *str < 58)
		digit = (digit * 10) + ((*str++) - 48);
	if (znak == 1 && digit >= 9223372036854775807u)
		return (-1);
	if (znak == -1 && digit >= 9223372036854775808u)
		return (0);
	return (digit * znak);
}
