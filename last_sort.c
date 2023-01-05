/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:33:37 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/05 22:34:58 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void last_sort(t_stack **stack_a, t_stack **stack_b)
{
	chunks_utils utils;
	int max;

	utils.size = get_size(*stack_a);
	utils.chunks_size = utils.size / 8;
	if (utils.size >= 500)
		utils.chunks_size = utils.size / 11;
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

	while (*stack_b)
	{
		max = get_max(*stack_b);
		best_move_top(utils, stack_b, max);
		push_top_a(stack_a, stack_b);
	}
}
