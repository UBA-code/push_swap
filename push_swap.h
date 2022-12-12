/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:08:30 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/12 00:36:10 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
static	char	*ft_strncpy(char *dest, char *src, size_t n);
size_t	ft_strlen(const char *s);
void	ft_error(char *msg);
int		ft_atoi(char *nb);
void	lst_new_add_back(int nb, t_stack **head);
t_stack	*create_stack(char **argv, int len);

#endif