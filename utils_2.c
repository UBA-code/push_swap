/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:23:52 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/25 01:47:45 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int get_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->num);
}

int get_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void ft_swap(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void move_top(chunks_utils utils, t_stack **stack, int num)
{
	int i;
	t_stack *current;

	current = *stack;
	i = 0;
	while (current)
	{
		if (current->num == num)
		{
			if (i <= utils.size / 2)
			{
				while ((*stack)->num != num)
				{
					swap_top_bottom(stack);
					ft_putstr("ra\n");
				}
				return;
			}
			while ((*stack)->num != num)
			{
				swap_bottom_top(stack);
				ft_putstr("rra\n");
			}
			return;
		}
		i++;
		current = current->next;
	}
}
