/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:36:58 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/19 15:25:52 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int num;

	num = 0;
	while (stack->next)
	{
		if (num < stack->num)
			num = stack->num;
		stack = stack->next;
	}
	if (num < stack->num)
		num = stack->num;
	return (num);
}

int	get_min(t_stack *stack)
{
	int num;

	num = get_max(stack);
	while (stack->next)
	{
		if (num > stack->num)
			num = stack->num;
		stack = stack->next;
	}
	if (num > stack->num)
		num = stack->num;
	return (num);
}

void	swap_max_min_top(t_stack **stack_a, t_stack **stack_b)
{
	int max;
	int min;
	int counter;

	counter = 0;
	max = get_max(*stack_a);
	min = get_min(*stack_a);
	while (counter < 2)
	{
		if ((*stack_a)->num == max || (*stack_a)->num == min)
		{
			push_top_b(stack_a, stack_b);
			counter++;
			continue ;
		}
		swap_top_bottom(stack_a);
		ft_putstr("ra\n");
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int min;

	min = get_min(*stack_a);
	swap_max_min_top(stack_a, stack_b);
	sort_three(stack_a);
	if ((*stack_b)->num != min)
	{
		swap_top_two(stack_b);
		ft_putstr("sb\n");
	}
	push_top_a(stack_a, stack_b);
	push_top_a(stack_a, stack_b);
	swap_top_bottom(stack_a);
	ft_putstr("ra\n");
}

