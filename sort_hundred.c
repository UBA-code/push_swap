/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/21 22:54:50 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort(char *str, t_stack *stack)
{
	int i;
	int x;

	i = 0;
	while (stack->next)
	{
		str[i] = 
	}
}

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	char *sorted;

	sorted = malloc(sizeof(char) * (get_size(stack_a) + 1));
	sort(sorted, *stack_a);
	while (*stack_a)
	{
		swap_min_top(stack_a);
		push_top_b(stack_a, stack_b);
	}
	while (*stack_b)
		push_top_a(stack_a, stack_b);
}
