/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:50:34 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 17:23:01 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	stack_sorted(char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i])
		i++;
	while (j < i - 1)
	{
		if (ft_atoi(args[j]) < ft_atoi(args[j + 1]))
			j++;
		else
			return ;
	}
	exit(0);
}

static int	skip_sign(char *nb, int *i, int *sign)
{
	int	j;

	j = 0;
	*sign = 1;
	while (nb[*i] == '-' || nb[*i] == '+')
	{
		if (nb[*i] == '-')
			*sign = -1;
		j++;
		++*i;
	}
	if (j > 1)
		return (0);
	return (1);
}

long long	ft_atoi(char *nb)
{
	size_t		i;
	int			sign;
	long long	n;

	i = 0;
	n = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	if (!skip_sign(nb, (int *)&i, &sign))
		ft_error("Error\n");
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		n *= 10;
		n += (nb[i] - '0');
		i++;
	}
	return (n * sign);
}

void	ft_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i], 1);
		i++;
	}
	exit(1);
}
