/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:11:12 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/12 00:39:06 by ybel-hac         ###   ########.fr       */
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
	
	stack_a = create_stack(argv, argc - 1);
	printf_list(stack_a);
	// check_args(argc - 1, argv);
	return (0);
}


/* print linked list */

/*
	t_stack *temp;

	temp = head;
	while (temp)
	{
		printf("%d\n", temp->num);
		temp = temp->next;
	}
*/