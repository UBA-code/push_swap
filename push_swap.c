/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:12 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/15 17:37:45 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_list(t_stack *head)
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
	stack_b = create_stack(args, argc);
	return (0);
}
