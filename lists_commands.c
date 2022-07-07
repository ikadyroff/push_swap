/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:25:09 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/12 22:23:51 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->flag = 0;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*set_last_node(t_node *node)
{
	if (!node)
		return (node);
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*set_first_node(t_node *node)
{
	if (!node)
		return (node);
	while (node->prev)
		node = node->prev;
	return (node);
}

void	add_node_back(t_node **node, t_node *new)
{
	if (!node || !new)
		return ;
	if (*node)
	{
		set_last_node(*node)->next = new;
		new->prev = *node;
	}
	else
		*node = new;
}

void	node_leaks(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}
