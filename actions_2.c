/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:55:05 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/13 12:57:57 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_two(stack_a);
	swap_top_two(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_bottom(stack_a);
	swap_top_bottom(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	swap_bottom_top(stack_a);
	swap_bottom_top(stack_b);
}
