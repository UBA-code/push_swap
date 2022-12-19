
void	ft_pustr(char *str);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:08:30 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/12/13 17:57:05 by ybel-hac         ###   ########.fr       */
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
size_t	ft_strlen(const char *s);
void	ft_error(char *msg);
int		ft_atoi(char *nb);
void	stack_sorted(char **args);
void	lst_new_add_back(int nb, t_stack **head);
t_stack	*create_stack(char **argv, int len);
void	swap_top_two(t_stack **stack);
void	swap_top_bottom(t_stack **stack);
void	swap_bottom_top(t_stack	**stack);
void	push_top_a(t_stack **stack_a, t_stack **stack_b);
void	push_top_b(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
char	**check_args(int *len, char **argv);
void	ft_putstr(char *str);
int	get_last(t_stack *stack);
int	case_one(t_stack **stack);
int	case_two(t_stack **stack);
int	case_three(t_stack **stack);
int	case_four(t_stack **stack);
int	case_five(t_stack **stack);
void	sort_three(t_stack **stack);
int get_tab_len(char **tab);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int	get_max(t_stack *stack);
int	get_min(t_stack *stack);
void sort_hundred(t_stack **stack_a, t_stack **stack_b);

#endif