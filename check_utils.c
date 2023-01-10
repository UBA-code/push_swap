/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:01:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 12:36:20 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**check_args(int *len, char **argv)
{
	int		i;
	int		j;
	char	**args;
	int		temp_nb;

	i = 0;
	args = argv;
	if (--*len == 1 && argv[0])
	{
		args = ft_split(argv[0], ' ');
	}
	stack_sorted(args);
	temp_nb = ft_atoi(args[i]);
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				ft_error("some integers are duplicated\n");
			j++;
		}
		i++;
	}
	*len = i;
	return (args);
}
/*
int	get_tab_len(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}
*/