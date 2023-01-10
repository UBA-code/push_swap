/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:23:52 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 13:00:01 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top(t_chunks_utils utils, int num)
{
	int		i;
	t_stack	*current;

	current = *(utils.stack_a);
	i = 0;
	while (current && ++i)
	{
		if (current->num == num && i <= get_size(*(utils.stack_a)) / 2)
		{
			while ((*(utils.stack_a))->num != num)
				swap_top_bottom(utils.stack_a, "ra\n");
			return ;
		}
		else if (current->num == num && i >= get_size(*(utils.stack_a)) / 2)
		{
			while ((*(utils.stack_a))->num != num)
				swap_bottom_top(utils.stack_a, "rra\n");
			return ;
		}
		current = current->next;
	}
}

int	check_bottom_number(t_chunks_utils utils)
{
	if ((*(utils.stack_b))->num > get_last(*(utils.stack_a))
		|| get_last(*(utils.stack_a)) == utils.tab[utils.size_const - 1])
	{
		push_top_a(utils.stack_a, utils.stack_b);
		swap_top_bottom(utils.stack_a, "ra\n");
		return (1);
	}
	return (0);
}

void	move_help(t_chunks_utils utils, int num, char c)
{
	if (c == '1')
	{
		while ((*(utils.stack_b))->num != num)
		{
			if (check_bottom_number(utils))
				continue ;
			swap_top_bottom(utils.stack_b, "rb\n");
		}
		return ;
	}
	while ((*(utils.stack_b))->num != num)
	{
		if (check_bottom_number(utils))
			continue ;
		swap_bottom_top(utils.stack_b, "rrb\n");
	}
}

int	best_move_top(t_chunks_utils utils, t_stack **stack, int num)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	if (!current)
		return (1);
	while (current && ++i)
	{
		if (current->num == num && i <= get_size(*(utils.stack_b)) / 2)
		{
			move_help(utils, num, '1');
			return (1);
		}
		if (current->num == num && i >= get_size(*(utils.stack_b)) / 2)
		{
			move_help(utils, num, '2');
			return (1);
		}
		current = current->next;
	}
	swap_bottom_top(utils.stack_a, "rra\n");
	return (0);
}
