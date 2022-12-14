/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:15:28 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/09 20:45:15 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// search in range of chanks for numbers and pushing him to stack b
void chunk_work(t_chunks_utils *utils, int min, int max)
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

void chunks(t_chunks_utils *utils, int *tab)
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

void sort_hundred(t_stack **stack_a, t_stack **stack_b)
{
	t_chunks_utils utils;
	int max;

	utils.size = get_size(*stack_a);
	utils.i = 0;
	utils.tab = malloc(sizeof(int) * utils.size);
	utils.stack_a = stack_a;
	utils.stack_b = stack_b;
	sort(utils.tab, *stack_a, utils.size);
	while ((*stack_a)->next)
	{
		utils.chunks_size = get_size(*stack_a) / 2;
		chunks(&utils, &(utils.tab[utils.i]));
		utils.i += utils.chunks_size;
	}
	
	while (*stack_b)
	{
		max = get_max(*stack_b);
		best_move_top(utils, stack_b, max);
		push_top_a(stack_a, stack_b);
	}
}
