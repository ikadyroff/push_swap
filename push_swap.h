/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:23:12 by wlouveni          #+#    #+#             */
/*   Updated: 2022/03/14 11:49:15 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_node_param
{
	int		min;
	int		mid;
	int		max;
	int		flag;
}	t_node_param;

void			error(void);
char			**get_array(char **argv);
void			free_arr(char **arr);
void			is_double(char **arr);
void			arr_checking(char **arr);
int				*arg_handling(char **argv, int *size, char ***str_arr);
void			leaks_treating(char **arr);

t_node			*set_list(char **arr);
t_node			*ft_lstnew(int num);
t_node			*set_last_node(t_node *node);
t_node			*set_first_node(t_node *node);
void			add_node_back(t_node **node, t_node *new);
void			node_leaks(t_node *node);

void			swap(t_node **stack);
void			swap_a(t_node **stack_a);
void			swap_b(t_node **stack_b);
void			swap_a_and_b(t_node **stack_a, t_node **stack_b);

void			push_b(t_node **a_node, t_node **b_node);
void			push_a(t_node **a_node, t_node **b_node);

void			rotate(t_node **stack);
void			rotate_a(t_node **stack);
void			rotate_b(t_node **stack);
void			rotate_a_b(t_node **stack_a, t_node **stack_b);

void			rev_rotate(t_node **stack);
void			rev_rotate_a(t_node **stack);
void			rev_rotate_b(t_node **stack);
void			rev_rotate_a_b(t_node **stack_a, t_node **stack_b);

void			assign_index(t_node *stack_a, int size, int *arr);
int				list_size(t_node **stack);
int				is_list_sorted(t_node **stack, int size);
t_node			*min_in_stack(t_node **stack);
int				check_position_list(t_node **stack, t_node *list);

void			min_b(t_node **stack_a, t_node **stack_b);
void			sorting_2(t_node **stack_a);
void			sorting_3(t_node **stack_a);
void			sorting_5(t_node **stack_a, t_node **stack_b);
void			sorting_main(t_node **stack_a, int size, int *arr);

t_node			*max_in_stack(t_node **stack);
t_node_param	*new_param_node(void);
void			set_param_stack(t_node_param *new, t_node **stack);
void			set_flag_param(t_node_param *param);
t_node			*last_in_stack(t_node **stack);

void			check_min_b(t_node **a, t_node **b, t_node_param *param_t);
void			check_min(t_node **a, t_node **b, t_node_param *param_t);
void			in_b_dop(t_node **a, t_node **b, t_node_param *param_t);
void			in_rr(t_node **a, t_node **b, t_node_param *param_t);
void			in_b_first(t_node **a, t_node **b, t_node_param *param_t);

void			in_a(t_node **stack_a, t_node **stack_b, t_node_param *param);
void			in_b(t_node **stack_a, t_node **stack_b, t_node_param *param);
void			big_sorting(t_node **stack_a, t_node **stack_b, int size);

int				get_next_line(char **str);
void			command(t_node **a, t_node **b, char *str);
void			checher(t_node **stack_a, int size, int *arr);

void			pb_com(t_node **a, t_node **b);
void			pa_com(t_node **b, t_node **a);
void			rra_com(t_node **stack);
void			rrb_com(t_node **stack);
void			rrr_com(t_node **stack, t_node **stack2);
void			ra_com(t_node **stack);
void			rb_com(t_node **stack);
void			rr_com(t_node **stack, t_node **stack2);
void			sa_com(t_node	**stack);
void			sb_com(t_node	**stack);
void			ss_com(t_node	**stack1, t_node **stack2);

#endif