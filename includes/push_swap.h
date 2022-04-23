/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlupin <rlupin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 00:44:51 by rlupin            #+#    #+#             */
/*   Updated: 2022/03/31 01:14:33 by rlupin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647
# define MALL_ERR 1
# define ARG_ERR 2
# define RR_RA 1
# define RR_RB 2
# define RRR_RRA 3
# define RRR_RRB 4
# define RRA_RB 5
# define RRB_RA 6
# define FORWARD 1
# define BACKWARD 0

typedef struct s_stack
{
	int					num;
	int					a_score;
	int					ra_score;
	int					b_score;
	int					rb_score;
	int					cheapest_score;
	int					rotate_variants;
	struct s_stack		*next;
}						t_stack;

typedef struct s_data
{
	int					*num_arr;
	int					*srt_num_arr;

	int					len;
	int					min;
	int					max;
	int					med;
	int					len_a;
	int					len_b;
	int					num_to_push;

	t_stack				*stack_a;
	t_stack				*stack_b;
}						t_data;

int						maint(int as, char **av);

void					ft_to_int(t_data *data, char **arr);
void					ft_int_check(t_data *data, long n, int la, char **arr);
void					ft_char_check(char **arr);
char					**ft_divided_args(int ac, char **av);
void					ft_reader(t_data *data, int ac, char **av);

void					ft_fill_list_a(t_data *data);
void					ft_fill_list_b(t_data *data);
void					ft_sort_if_five(t_data *data);
void					ft_main_algorithm(t_data *data);
void					ft_distribut(t_stack *stack, t_data *data);

void					ft_stop1(char **arr, int flag);
void					ft_stop2(char **att, t_data *data, int flag);
void					ft_stop3(t_data *data);
void					ft_stop4(t_data *data);
void					ft_stop5(t_data *data);

void					ft_swap_a(t_stack **stack_a);
void					ft_swap_b(t_stack **stack_b);
void					ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void					ft_pa(t_stack **s_a, t_stack **s_b, int *l_a, int *l_b);
void					ft_pb(t_stack **s_a, t_stack **s_b, int *l_a, int *l_b);
void					ft_rotate_a(t_stack **stack_a);
void					ft_rotate_b(t_stack **stack_b);
void					ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void					ft_rev_rotate_a(t_stack **stack_a);
void					ft_rev_rotate_b(t_stack **stack_b);
void					ft_rev_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void					ft_rev_ab_b(t_stack **stack_b);
void					ft_rev_ab_a(t_stack **stack_a);

void					ft_rr_ra_move(t_stack *stack, t_data *data);
void					ft_rr_rb_move(t_stack *stack, t_data *data);
void					ft_rrr_rrb_move(t_stack *stack, t_data *data);
void					ft_rrr_rra_move(t_stack *stack, t_data *data);
void					ft_rra_rb_move(t_stack *stack, t_data *data);
void					ft_rrb_ra_move(t_stack *stack, t_data *data);

void					ft_scoring(t_data *data);
int						ft_scoring_a(t_stack *stack_a, int num);
void					ft_find_option(t_stack *tmp, int len_a, int len_b);
t_stack					*ft_elem_to_push(t_stack *stack_b);

int						ft_rr_ra_opt(t_stack *tmp, int len_a);
int						ft_rr_rb_opt(t_stack *tmp, int len_b);
int						ft_rrr_rrb_opt(t_stack *tmp, int len_b);
int						ft_rrr_rra_opt(t_stack *tmp, int len_a);
int						ft_rra_rb_opt(t_stack *tmp);
int						ft_rrb_ra_opt(t_stack *tmp);

int						ft_new_putendl_fd(char *s, int fd);
long					ft_new_atoi(const char *str);
int						arr_len(char **arr);

void					ft_srt_arr(t_data *data);
void					ft_quick_sort_recursive(int *mas, int size);

t_stack					*ft_new_lstnew(t_data *data, int i);
void					ft_new_lstadd_front(t_stack **lst, t_stack *new);
void					ft_new_lstadd_back(t_stack **lst, t_stack *new);

void					ft_triple_sorting(t_data *data);
void					ft_final_sorting(t_data *data);
int						ft_rotate_dir(t_data *data);
int						ft_if_sorted(t_stack *stack);
int						ft_sorted_inner(t_stack *stack, t_stack *tmp);

#endif