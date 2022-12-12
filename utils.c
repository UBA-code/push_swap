/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 17:50:34 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/11 19:43:22 by ybel-hac         ###   ########.fr       */
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
/*
int	stack_sorted(t_stack head, int len)
{
	int n1;
	int n2;

	while (head)
	{
		n1 = head.num;
		n2 = head.next->num;
		if (n1 < n2)
			head = head.next;
		else
			return (0);
	}
	return (1);
}
*/
static int	skip_sign(char *nb, int *i, int *sign)
{
	int j;

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

int	ft_atoi(char *nb)
{
	int i;
	int	sign;
	int n;

	i = 0;
	n = 0;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == ' ')
		i++;
	if (!skip_sign(nb, &i, &sign))
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
	int i;

	i = 0;
	while (msg[i])
	{
		write(2, &msg[i],1);
		i++;
	}
	exit(1);
}