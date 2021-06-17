/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:10:51 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 02:33:54 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define A 1
# define B 2
# define ALL 3

# define BASIC 100
# define INT_RANGE 101
# define MALLOC_ERR 102
# define NO_NUM 103
# define SAME_NUM 104

typedef struct		s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
	int				index;
}					t_node;

typedef struct		s_stack
{
	t_node			*head;
	t_node			*tail;
	int				total;
	int				max;
	int				post_max;
}					t_stack;

typedef struct		s_sort
{
	int				s_pivot;
	int				b_pivot;
	int				hiden_pivot;
	int				cnt_ra;
	int				cnt_pa;
}					t_sort;

/*
** ps_free.c
*/
void				ps_free_a(t_stack *a);
void				ps_free_b(t_stack *b);
void				ps_free_all(t_stack *a, t_stack *b);

/*
** ps_init.c
*/
t_stack				*init_stack(void);
t_node				*init_node(void);
void				init_sort(t_sort *sort);

/*
** ps_utils.c
*/
void				push_stack_one(t_stack *from, t_stack *to);
void				ps_putendl_fd(char *s, int fd);
void				ps_error(int flag);
int					ps_atoi_utils(const char str[], long long numb);
int					ps_atoi(const char *str);

/*
** ps_linked.c
*/
void				connect_node(t_node *temp, t_node **node, t_stack *a);
int					make_node(char *argv, t_node **node, t_stack *a);
void				duplicate_data(t_node *node);
void				set_stack(int argc, char **argv, t_stack *a);

/*
** ps_double.c
*/
void				reverse_double_rotate(t_stack *a, t_stack *b, int flag);
void				rotate_rotate(t_stack *a, t_stack *b, int flag);
void				swap_swap(t_stack *a, t_stack *b, int flag);

/*
** ps_push_pop.c
*/
void				reverse_rotate_stack(t_stack *stack, int flag);
void				rotate_stack(t_stack *stack, int flag);
void				swap_stack(t_stack *stack, int flag);
void				ps_total_zero(t_stack *from, t_stack *to);
void				push_stack(t_stack *from, t_stack *to, int flag);

/*
** ps_prev_stack.c
*/
int					max(t_node *node, int total);
void				give_index(t_node *node, t_stack *stack,
int index, int min);
void				find_index(t_node *node, t_stack *stack);
/*
** ps_sort.c
*/
int					min_index(t_node *node, int total);
int					max_index(t_node *node, int total);
void				select_pivot_b(t_sort *sort, t_stack *stack);
void				select_pivot(t_sort *sort, t_stack *stack);

/*
** ps_atob.c
*/
void				re_one_third(t_stack *a, t_stack *b, t_sort *sort);
void				re_btoa(int total, t_stack *a, t_stack *b);
void				ps_atob_div(t_stack *a, t_stack *b, t_sort *sort);
void				atob(int total, t_stack *a, t_stack *b);

/*
** ps_btoa.c
*/
void				ps_push_max_down(t_stack *a, t_stack *b, int cnt);
void				ps_push_max_up(t_stack *a, t_stack *b, int cnt);
void				ps_push_max(t_stack *a, t_stack *b, int cnt);
int					ps_search_max(t_stack *b);
void				btoa(int total, t_stack *a, t_stack *b);

/*
** ps_under_five.c
*/
int					find_mid(t_stack *stack, int total);
void				three_index(t_stack *a, int total);
void				four_index(t_stack *a, t_stack *b, int real_total);
void				five_index(t_stack *a, t_stack *b, int real_total);
void				under_five(t_stack *a, t_stack *b, int total);

/*
** push_swap.c
*/
int					main(int argc, char **argv);

#endif
