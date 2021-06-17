/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soooh <soooh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:18:17 by soooh             #+#    #+#             */
/*   Updated: 2021/06/18 02:36:44 by soooh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/libft.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
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
** ck_double.c
*/
void				reverse_double_rotate(t_stack *a, t_stack *b, int flag);
void				rotate_rotate(t_stack *a, t_stack *b, int flag);
void				swap_swap(t_stack *a, t_stack *b, int flag);

/*
** ck_push_pop.c
*/
void				reverse_rotate_stack(t_stack *stack, int flag);
void				rotate_stack(t_stack *stack, int flag);
void				swap_stack(t_stack *stack, int flag);
void				ps_total_zero(t_stack *from, t_stack *to);
void				push_stack(t_stack *from, t_stack *to, int flag);

/*
** ck_free.c
*/
void				ps_free_a(t_stack *a);
void				ps_free_b(t_stack *b);
void				ps_free_all(t_stack *a, t_stack *b);

/*
** ck_init.c
*/
t_stack				*init_stack(void);
t_node				*init_node(void);
void				init_sort(t_sort *sort);

/*
** ck_linked.c
*/
void				connect_node(t_node *temp, t_node **node, t_stack *a);
int					make_node(char *argv, t_node **node, t_stack *a);
void				duplicate_data(t_node *node);
void				set_stack(int argc, char **argv, t_stack *a);

/*
** ck_prev_stack.c
*/
int					max(t_node *node, int total);
void				give_index(t_node *node, t_stack *stack,
int index, int min);
void				find_index(t_node *node, t_stack *stack);

/*
** ck_utils.c
*/
void				push_stack_one(t_stack *from, t_stack *to);
void				ps_putendl_fd(char *s, int fd);
void				ps_error(int flag);
int					ps_atoi_utils(const char str[], long long numb);
int					ps_atoi(const char *str);

/*
** checker_op.c
*/
void				ck_reverse_rotate(t_stack *a, t_stack *b, char *buf);
void				ck_rotate(t_stack *a, t_stack *b, char *buf);
void				ck_swap(t_stack *a, t_stack *b, char *buf);
void				ck_push(t_stack *a, t_stack *b, char *buf);
void				checker_op(t_stack *a, t_stack *b, char *buf);

/*
** checker.c
*/
int					ck_sort(t_stack *a);
void				checker(t_stack *a, t_stack *b);
int					main(int argc, char *argv[]);

#endif
