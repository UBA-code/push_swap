/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/18 19:25:25 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_min_top(t_stack **stack)
{
	int min;

	min = get_min(*stack);
	while (1)
	{
		if ((*stack)->num == min)
			return ;
		swap_top_bottom(stack);
		ft_putstr("ra\n");
	}
}

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int min;

	while ((*stack_a)->next)
	{
		swap_min_top(stack_a);
		push_top_b(stack_a, stack_b);
	}
	min = get_min(*stack_a);
	if ((*stack_a)->num == min)
		push_top_b(stack_a, stack_b);
	while ((*stack_b)->next)
		push_top_a(stack_a, stack_b);
	push_top_a(stack_a, stack_b);
}