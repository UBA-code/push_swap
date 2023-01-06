/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:12 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/07 00:24:10 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *head)
{
	t_stack *temp;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
}


int main (int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **args;

	args = check_args(&argc, argv + 1);
	stack_a = create_stack(args, argc);
	stack_b = NULL;
	// sort_three(&stack_a);
	// sort_five(&stack_a, &stack_b);
	last_sort(&stack_a, &stack_b);
	// printf("\nstack a\n\n");
	// print_list(stack_a);
	// printf("------------\nstack b\n\n");
	// print_list(stack_b);
	return (0);
}
