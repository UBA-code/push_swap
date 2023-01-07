/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:23:52 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/07 22:53:48 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

int get_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void ft_swap(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void move_top(chunks_utils utils, int num, int min, int max)
{
	int i;
	t_stack *current;

	current = *(utils.stack_a);
	i = 0;
	while (current && ++i)
	{
		if (current->num == num && i <= get_size(*(utils.stack_a)) / 2)
		{
			while ((*(utils.stack_a))->num != num)
				swap_top_bottom(utils.stack_a, "ra\n");
			return ;
		}
		else if (current->num == num && i >= get_size(*(utils.stack_a)) / 2)
		{
			while ((*(utils.stack_a))->num != num)
				swap_bottom_top(utils.stack_a, "rra\n");
			return ;
		}
		current = current->next;
	}
}

void best_move_top(chunks_utils utils, t_stack **stack, int num)
{
	t_stack *current;
	int i;

	i = 0;
	current = *stack;
	if (!current)
		return ;
	while (current && ++i)
	{
		if (current->num == num && i <= get_size(*(utils.stack_b)) / 2)
		{
			while ((*stack)->num != num)
				swap_top_bottom(stack, "rb\n");
			return ;
		}
		if (current->num == num && i >= get_size(*(utils.stack_b)) / 2)
		{
			while ((*stack)->num != num)
				swap_bottom_top(stack, "rrb\n");
			return ;
		}
		current = current->next;
	}
}
