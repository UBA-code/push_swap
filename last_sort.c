/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:33:37 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/09 15:08:26 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted(t_stack *stack)
{
	t_stack *current;

	current = stack;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int get_pos(int *tab, int size, int num)
{
	int i;

	i = 0;
	while (size > 0)
	{
		if (tab[i] == num)
			return (i);
		i++;
		size--;
	}
	return (0);
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
			if (get_pos(utils->tab, utils->size, (*(utils->stack_b))->num) < utils->size / 2)
				swap_top_bottom(utils->stack_b, "rb\n");
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
	int last;

	chunk_size_temp = utils->size / 2 + utils->i;
	max = 0;
	last = 0;
	while (last < utils->size && chunk_size_temp > 0)
	{
		last++;
		max++;
		chunk_size_temp--;
	}
	max = tab[max - 1];
	if (utils->size / 2 - utils->i <= 0)
		min = tab[0];
	else
		min = tab[utils->size / 2 - utils->i];
	chunk_work(utils, min, max);
}

void last_sort(t_stack **stack_a, t_stack **stack_b)
{
	chunks_utils utils;
	int max;

	utils.size = get_size(*stack_a);
	utils.size_const = utils.size;
	utils.chunks_size = utils.size / 8;
	if (utils.size >= 500)
		utils.chunks_size = utils.size / 19;
	utils.i = utils.chunks_size;
	utils.tab = malloc(sizeof(int) * utils.size);
	utils.stack_a = stack_a;
	utils.stack_b = stack_b;
	sort(utils.tab, *stack_a, utils.size);
	while (*stack_a)
	{
		chunks(&utils, utils.tab);
		utils.i += utils.chunks_size;
	}
	while (*stack_b)
	{
		max = utils.tab[--(utils.size)];
		if (best_move_top(utils, stack_b, max))
			push_top_a(stack_a, stack_b);
	}
	free(utils.tab);
}
