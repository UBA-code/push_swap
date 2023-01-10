/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 00:18:47 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 12:39:37 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->next)
	{
		i++;
		stack = stack->next;
	}
	i++;
	return (i);
}

int	get_position(t_stack *stack, int num)
{
	int	i;
	int	len;

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
	int	i;

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
	int	i;
	int	x;

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
