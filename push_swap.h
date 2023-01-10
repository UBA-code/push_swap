/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:08:30 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/01/10 12:45:52 by ybel-hac         ###   ########.fr       */
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

typedef struct s_t_chunks_utils
{
	int		*tab;
	int		size;
	int		i;
	int		chunks_size;
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		size_const;
}	t_chunks_utils;

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	ft_error(char *msg);
int		ft_atoi(char *nb);
void	stack_sorted(char **args);
void	lst_new_add_back(int nb, t_stack **head);
t_stack	*create_stack(char **argv, int len);
void	swap_top_two(t_stack **stack, char *str);
void	swap_top_bottom(t_stack **stack, char *str);
void	swap_bottom_top(t_stack **stack, char *str);
void	push_top_a(t_stack **stack_a, t_stack **stack_b);
void	push_top_b(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
char	**check_args(int *len, char **argv);
void	ft_putstr(char *str);
int		get_last(t_stack *stack);
int		case_one(t_stack **stack);
int		case_two(t_stack **stack);
int		case_three(t_stack **stack);
int		case_four(t_stack **stack);
int		case_five(t_stack **stack);
void	sort_three(t_stack **stack);
int		get_tab_len(char **tab);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
void	last_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(int *n1, int *n2);
void	move_top(t_chunks_utils utils, int num, int min, int max);
int		best_move_top(t_chunks_utils utils, t_stack **stack, int num);
int		get_size(t_stack *stack);
void	sort(int *tab, t_stack *stack, int size);
int		get_pos(int *tab, int size, int num);
int		check_sorted(t_stack *stack);

void	print_list(t_stack *head);

#endif