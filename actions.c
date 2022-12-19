/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:25:52 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/16 19:50:42 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_two(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack temp;

	first = *stack;
	second = first->next;
	*stack = second;
	temp = *second;
	second->next = first;
	first->next = temp.next;
}

void	swap_top_bottom(t_stack **stack)
{
	t_stack	*last;
	t_stack	*temp;

	last = *stack;
	temp = *stack;
	*stack = last->next;
	while (last->next)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
}

void	swap_bottom_top(t_stack	**stack)
{
	t_stack *first;
	t_stack *last;
	t_stack	*before_last;

	first = *stack;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	*stack = last;
	last->next = first;
	before_last->next = NULL;
}

void	push_top_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*element_a;
	t_stack	*element_b;

	element_a = *stack_a;
	element_b = *stack_b;
	*stack_b = element_b->next;
	element_b->next = *stack_a;
	*stack_a = element_b;
	ft_putstr("pa\n");
}

void	push_top_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *element_a;
	t_stack *element_b;

	element_a = *stack_a;
	*stack_a = element_a->next;
	element_b = *stack_b;
	element_a->next = element_b;
	*stack_b = element_a;
	ft_putstr("pb\n");
}
