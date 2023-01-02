/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:36:55 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/02 02:25:11 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	case_one(t_stack **stack)
{
	int last;

	last = get_last(*stack);
	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < last
		&& last > (*stack)->num)
	{
		swap_top_two(stack, "sa\n");
		return (1);
	}
	return (0);
}

int	case_two(t_stack **stack)
{
	int last;

	last = get_last(*stack);
	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num > last
		&& last < (*stack)->num)
	{
		swap_top_two(stack, "sa\n");
		swap_bottom_top(stack, "rra\n");
		return (1);
	}
	return (0);
}

int	case_three(t_stack **stack)
{
	int last;

	last = get_last(*stack);
	if ((*stack)->num > (*stack)->next->num && (*stack)->next->num < last
		&& last < (*stack)->num)
	{
		swap_top_bottom(stack, "ra\n");
		return (1);
	}
	return (0);
}

int	case_four(t_stack **stack)
{
	int last;

	last = get_last(*stack);
	if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > last
		&& last > (*stack)->num)
	{
		swap_top_two(stack, "sa\n");
		swap_top_bottom(stack, "ra\n");
		return (1);
	}
	return (0);
}

int	case_five(t_stack **stack)
{
	int last;

	last = get_last(*stack);
	if ((*stack)->num < (*stack)->next->num && (*stack)->next->num > last
		&& last < (*stack)->num)
	{
		swap_bottom_top(stack, "rra\n");
		return (1);
	}
	return (0);
}