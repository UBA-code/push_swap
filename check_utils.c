/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:01:26 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/16 16:35:55 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_num(char *num)
{
	int	i;

	i = 0;
	if (ft_strlen(num) == 0)
		ft_error("Error\n");
	while (num[i])
	{
		if (!((num[i] >= '0' && num[i] <= '9')
				|| num[i] == '-' || num[i] == '+') || num[i] == ' ')
			ft_error("Error\n");
		i++;
	}
	if (!(num[i - 1] >= '0' && num[i - 1] <= '9'))
		ft_error("Error\n");
}

void	check_dup(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

char	**check_args(int *len, char **argv, char *type)
{
	int		i;
	char	**args;

	i = 0;
	args = argv;
	if (*len == 1)
		exit(0);
	if (--*len == 1 && ft_atoi(argv[0]))
		args = ft_split(argv[0], ' ');
	while (args[i])
	{
		check_num(args[i]);
		if (ft_atoi(args[i]) > INT_MAX)
			ft_error("Error\n");
		i++;
	}
	check_dup(args);
	stack_sorted(args, type);
	*len = i;
	return (args);
}
