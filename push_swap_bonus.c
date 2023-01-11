/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:16:32 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/11 16:53:19 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_actions(char *actions)
{
	if (ft_strcmp(actions, "sa\n") || ft_strcmp(actions, "sb\n"))
		return ;
	else if (ft_strcmp(actions, "ra\n") || ft_strcmp(actions, "rb\n"))
		return ;
	else if (ft_strcmp(actions, "rra\n") || ft_strcmp(actions, "rrb\n"))
		return ;
	else if (ft_strcmp(actions, "rrr\n")
		|| ft_strcmp(actions, "ss\n") || ft_strcmp(actions, "rr\n"))
		return ;
	else if (ft_strcmp(actions, "pa\n") || ft_strcmp(actions, "pb\n"))
		return ;
	else
		ft_error("Error\n");
}

char	**get_actions(void)
{
	char	*actions_tab;
	char	*final_tab;
	char	**splited;

	actions_tab = get_next_line(0);
	final_tab = 0;
	if (!actions_tab)
		exit(0);
	while (actions_tab)
	{
		check_actions(actions_tab);
		final_tab = ft_strjoin(final_tab, actions_tab);
		free(actions_tab);
		actions_tab = get_next_line(0);
	}
	splited = ft_split(final_tab, '\n');
	return (splited);
}

void	actions_work(char *action, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(action, "sa"))
		swap_top_two_bonus(stack_a);
	else if (ft_strcmp(action, "sb"))
		swap_top_two_bonus(stack_b);
	else if (ft_strcmp(action, "ss"))
		ss_bonus(stack_a, stack_b);
	else if (ft_strcmp(action, "pa"))
		push_top_a_bonus(stack_a, stack_b);
	else if (ft_strcmp(action, "pb"))
		push_top_b_bonus(stack_a, stack_b);
	else if (ft_strcmp(action, "ra"))
		swap_top_bottom_bonus(stack_a);
	else if (ft_strcmp(action, "rb"))
		swap_top_bottom_bonus(stack_b);
	else if (ft_strcmp(action, "rra"))
		swap_bottom_top_bonus(stack_a);
	else if (ft_strcmp(action, "rrb"))
		swap_bottom_top_bonus(stack_b);
	else if (ft_strcmp(action, "rr"))
		rr_bonus(stack_a, stack_b);
	else if (ft_strcmp(action, "rrr"))
		rrr_bonus(stack_a, stack_b);
}

void	sort_work(t_bonus_utils utils, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (utils.actions[i])
	{
		actions_work(utils.actions[i], stack_a, stack_b);
		i++;
	}
	if (check_sorted(*(stack_a)) && !*(stack_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_bonus_utils	utils;

	utils.args = check_args(&argc, argv + 1);
	utils.stack_a = create_stack(utils.args, argc);
	utils.stack_b = NULL;
	utils.actions = get_actions();
	utils.stack_a_add = &(utils.stack_a);
	utils.stack_b_add = &(utils.stack_b);
	sort_work(utils, utils.stack_a_add, utils.stack_b_add);
}
