/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/01 20:46:58 by ybel-hac         ###   ########.fr       */
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

void stack_to_arr(t_stack *stack, int *tab)
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

void sort(int *tab, t_stack *stack, int size)
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

// search in range of chanks for numbers and pushing him to stack b
void chunk_work(chunks_utils *utils, int min, int max)
{
	t_stack *current;

	current = *(utils->stack_a);
	while (current)
	{
		if (current->num >= min && current->num <= max)
		{
			move_top(*utils, current->num, min, max);
			push_top_b(utils->stack_a, utils->stack_b);
			current = *(utils->stack_a);
			continue;
		}
		current = current->next;
	}
}

void chunks(chunks_utils *utils, int *tab)
{
	int min;
	int max;
	int chunk_size_temp;
	static int last;

	chunk_size_temp = utils->chunks_size;
	max = 0;
	while (last < utils->size && chunk_size_temp > 0)
	{
		last++;
		max++;
		chunk_size_temp--;
	}
	max = tab[max - 1];
	min = tab[0];
	chunk_work(utils, min, max);
}

void	best_move_top(chunks_utils utils, t_stack **stack, int num)
{
	t_stack *current;
	int i;

	i = 0;
	current = *stack;
	while (current)
	{
		if (current->num == num && i <= utils.size / 2)
		{
			while ((*stack)->num != num)
			{
				swap_top_bottom(stack);
				ft_putstr("ra\n");
			}
			return ;
		}
		if (current->num == num && i >= utils.size / 2)
		{
			while ((*stack)->num != num)
			{
				swap_bottom_top(stack);
				ft_putstr("rra\n");
			}
			return ;
		}
		i++;
		current = current->next;
	}
}

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	chunks_utils utils;
	int max;

	utils.size = get_size(*stack_a);
	utils.chunks_size = utils.size / 8;
	utils.i = 0;
	utils.tab = malloc(sizeof(int) * utils.size);
	utils.stack_a = stack_a;
	utils.stack_b = stack_b;
	sort(utils.tab, *stack_a, utils.size);                 
	while (*stack_a)
	{
		chunks(&utils, &(utils.tab[utils.i]));
		utils.i += utils.chunks_size;
	}
	/*
	while (*stack_b)
	{
		max = get_max(*stack_b);
		best_move_top(utils, stack_b, max);
		push_top_a(stack_a, stack_b);
	}
	*/
}
