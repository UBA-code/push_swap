/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:12 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/17 13:51:10 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	basic_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	min;

	size = get_size(*stack_a);
	if (size == 2)
		swap_top_two(stack_a, "sa\n");
	else if (size == 4)
	{
		min = get_min(*stack_a);
		while ((*(stack_a))->num != min)
			swap_top_bottom(stack_a, "ra\n");
		push_top_b(stack_a, stack_b);
		sort_three(stack_a);
		push_top_a(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	args = check_args(&argc, argv + 1, "mandatory");
	stack_a = create_stack(args, argc);
	stack_b = NULL;
	if (get_size(stack_a) <= 2 || get_size(stack_a) == 4)
		basic_sort(&stack_a, &stack_b);
	else if (get_size(stack_a) == 3)
		sort_three(&stack_a);
	else if (get_size(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	else
	{
		last_sort(&stack_a, &stack_b);
		while (!check_sorted(stack_a))
			swap_bottom_top(&stack_a, "rra\n");
	}
	return (0);
}
