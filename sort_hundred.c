/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/22 20:23:46 by ybel-hac         ###   ########.fr       */
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

void	stack_to_arr(t_stack *stack, int *tab)
{
	int i;

	i = 0;
	while (stack->next)
	{
		tab[i] = stack->num;
		stack = stack->next;
		i++;
	}
	tab[i] = stack->num;
}

void	sort(int *tab, t_stack *stack, int size)
{
	int i;
	int x;

	i = 0;
	stack_to_arr(stack, tab);
	while (i < size)
	{
		x = i;
		while (x < size)
		{
			if (tab[x] < tab[i])
				ft_swap(&tab[i], &tab[x]);
			x++;
		}
		i++;
	}
}

void chunks(t_stack **stack_a, t_stack **stack_b, int *tab)
{
		
}

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int *tab;
	int size;
	int i;

	i = 0;
	size = get_size(stack_a);
	tab = malloc(sizeof(int) * size);
	sort(&tab, *stack_a, size);
	while (*stack_a)
	{
		chunks(stack_a, stack_b, &tab);
	}
}
