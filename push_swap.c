/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:12 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 12:37:43 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	args = check_args(&argc, argv + 1);
	stack_a = create_stack(args, argc);
	stack_b = NULL;
	if (get_size(stack_a) == 3)
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
