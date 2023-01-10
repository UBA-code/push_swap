/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:16:32 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 21:05:24 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_bonus_utils
{
	t_stack *stack_a;
	t_stack *stack_b;
	char **actions;
	char **args;
} t_bonus_utils;

char **get_actions()
{
	char *actions_tab;
	char *final_tab;
	char *temp;

	actions_tab = get_next_line(1);
	while (actions_tab)
	{
		temp = final_tab;
		final_tab = ft_strjoin(final_tab, actions_tab);
		free(temp);
		free(actions_tab);
		actions_tab = get_next_line(1);
	}
}

int main(int argc, char **argv)
{
	t_bonus_utils utils;
	char *actions_tab;
	char *final_tab;
	char *temp;
	// utils.stack_a = create_stack(argv, argc - 1);
	utils.stack_b = NULL;
	// utils.args = get_actions();
	temp = final_tab;
	final_tab = ft_strjoin(final_tab, actions_tab);
	free(temp);
	free(actions_tab);
}
