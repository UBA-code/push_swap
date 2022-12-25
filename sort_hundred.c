/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/25 01:52:05 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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

void chunk_work(chunks_utils *utils, int min, int max)
{
	t_stack *current;
	int i;

	i = 0;
	current = *(utils->stack_a);
	while (current->next)
	{
		if (current->num >= min && current->num <= max)
		{
			
		}
			push_top_b(utils->stack_a, utils->stack_b);
		current = current->next;
	}
}

void chunks(chunks_utils *utils, int *tab)
{
	int min;
	int max;
	int chunk_size_temp;
	int i;

	chunk_size_temp = utils.chunk_size;
	// here maybe sigfault will be get because the chunks size not in all time fixed
	max = tab[utils->chunks_size];
	min = tab[0];
	chunk_work(utils, min, max);
}

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	chunks_utils utils;

	utils.size = get_size(stack_a);
	utils.chunks_size = utils.size / 10;
	utils.i = 0;
	utils.tab = malloc(sizeof(int) * utils.size);
	utils.stack_a = stack_a;
	utils.stack_b = stack_b;
	sort(&(utils.tab), *stack_a, utils.size);
	while (*stack_a)
	{
		chunks(&utils, &(utils.tab[utils.i]));
		utils.i += utils.chunks_size
	}
}
*/