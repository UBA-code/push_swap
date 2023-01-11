/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:55:05 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/11 12:43:21 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_bonus(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_two_bonus(stack_a);
	swap_top_two_bonus(stack_b);
}

void	rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	swap_top_bottom_bonus(stack_a);
	swap_top_bottom_bonus(stack_b);
}

void	rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	swap_bottom_top_bonus(stack_a);
	swap_bottom_top_bonus(stack_b);
}
