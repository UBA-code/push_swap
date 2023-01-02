/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:20:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/02 01:52:09 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack)
{
	swap_top_two(stack);
	ft_putstr("sa\n");
}

void	ra(t_stack **stack)
{
	swap_top_bottom(stack);
	ft_putstr("ra\n");
}

void	rra(t_stack **stack)
{
	swap_bottom_top(stack);
	ft_putstr("rra\n");
}

void	sb(t_stack **stack)
{
	swap_top_two(stack);
	ft_putstr("sb\n");
}

void	ra(t_stack **stack)
{
	swap_top_bottom(stack);
	ft_putstr("ra\n");
}

void	rra(t_stack **stack)
{
	swap_bottom_top(stack);
	ft_putstr("rra\n");
}