/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 17:48:43 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/11 19:05:14 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	calc_element(const char *s, char sep, size_t *x, size_t *j)
{
	size_t	i;
	size_t	len;

	*x = 0;
	*j = 0;
	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != sep)
		{
			if (s[i + 1] == sep || s[i + 1] == '\0')
				len++;
		}
		i++;
	}
	return (len);
}

static	void	get_next_str(const char *str, char c, size_t *i, size_t *j)
{
	*j = *i;
	while (str[*i])
	{
		if (str[*i] == c)
		{
			++*i;
			++*j;
		}
		else
			break ;
	}
}

static int	substr_and_alloc_check(char **final_str, const char *s,
				int j, int len)
{
	*final_str = ft_substr(s, j, len);
	if (!final_str)
		return (0);
	return (1);
}

static char	**free_tab(char **tab, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		free(tab[i]);
		i++;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**final_str;
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	final_str = calloc(sizeof(char *), calc_element(s, c, &x, &j) + 1);
	if (!final_str || !s)
		return (0);
	get_next_str(s, c, &i, &j);
	if (i-- == ft_strlen(s))
		return ((char *[1]){NULL});
	while (++i <= ft_strlen(s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			if (!substr_and_alloc_check(&final_str[x++], s, j, i - j))
				return (free_tab(final_str, --x));
			get_next_str(s, c, &i, &j);
		}
	}
	return (final_str);
}
