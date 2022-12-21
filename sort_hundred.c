/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/20 20:06:20 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_sort_hundred_utils
{
	int min;
	int max;
	int min_position;
	int max_position;
	int counter;
} sort_utils;

int get_size(t_stack *stack)
{
	int i;

	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	i++;
	return (i);
}

int get_position(t_stack *stack, int num)
{
	int i;
	int len;

	i = 0;
	len = get_size(stack);
	while (stack->next)
	{
		if (stack->num == num)
		{
			if (i > (len / 2))
				return (1);
			return (0);
		}
		i++;
		stack = stack->next;
	}
	if (i > (len / 2))
		return (1);
	return (0);
}

void swap_min_top(t_stack **stack_a, t_stack **stack_b)
{
	sort_utils utils;

	utils.counter = 0;
	while (*stack_a)
	{
		utils.min = get_min(*stack_a);
		utils.max = get_max(*stack_a);
		utils.min_position = get_position(*stack_a, utils.min);
		utils.max_position = get_position(*stack_a, utils.max);
		if ((*stack_a)->num == utils.min)
		{
			push_top_b(stack_a, stack_b);
			continue;
		}
		else if ((*stack_a)->num == utils.max)
		{
			push_top_b(stack_a, stack_b);
			swap_top_bottom(stack_b);
			ft_putstr("rb\n");
			continue;
		}
		if (utils.min_position == 1)
		
	}
}

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a)
	{
		swap_min_top(stack_a);
		push_top_b(stack_a, stack_b);
	}
	while (*stack_b)
		push_top_a(stack_a, stack_b);
}
