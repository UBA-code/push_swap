/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:55:05 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/02 01:57:45 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_two(stack_a, "sa\n");
	swap_top_two(stack_b, "sb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_bottom(stack_a, "ra\n");
	swap_top_bottom(stack_b, "rb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	swap_bottom_top(stack_a, "rra\n");
	swap_bottom_top(stack_b, "rrb\n");
}
