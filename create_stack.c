/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:36:18 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 13:01:38 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_new_add_back(int nb, t_stack **head)
{
	t_stack	*new;
	t_stack	*current;

	new = malloc(sizeof(t_stack));
	current = *head;
	new->num = nb;
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
	}
}

t_stack	*create_stack(char **argv, int len)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (len > 0)
	{
		lst_new_add_back(ft_atoi(argv[i++]), &stack);
		len--;
	}
	return (stack);
}
