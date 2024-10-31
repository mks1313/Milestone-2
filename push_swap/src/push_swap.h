/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:29:46 by mmarinov          #+#    #+#             */
/*   Updated: 2024/10/31 16:42:55 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_algorithm
{
	int		last_b;
	int		min_b;
	int		max_b;
	int		moves_b_ra;
	int		moves_b_rra;
	int		moves_a_ra;
	int		moves_a_rra;
	int		moves_a;
	int		moves_b;
	int		less_moves;
	int		position;
}	t_algorithm_data;

typedef struct s_stack
{
	int				number;
	int				position;
	struct s_stack	*next;
}	t_stack;

typedef struct s_parameters
{
	char	*line;
	char	**split;
	char	**arguments;
	int		length_a;
	int		length;
	t_stack	*a;
	t_stack	*b;
	t_stack	*perfection;
}	t_parameters;

/*Checkers*/
int				check_length(t_stack **a);
int				check_order(t_stack **a, int length);
void			check_duplicate(t_stack **a);
int				check_atoi(const char *str);
void			check_is_number(char **split);
/*Llenado de infomacion*/
t_stack			*fill_stack(t_parameters *parameters, char **split);
char			**fill_split(t_parameters *parameters, char **arguments);
void			fill_position(t_stack **a);
/*Operaciones ejecutables*/
void			p_stack(t_stack **a, t_stack **b, char c);
void			s_stack(t_stack **top, char c);
void			r_stack(t_stack **stack, char c);
void			r_rboth(t_stack **a, t_stack **b);
void			rr_stack(t_stack **stack, char c);
void			rr_rboth(t_stack **a, t_stack **b);
void			ft_stkadd_front(t_stack **stack, t_stack *new);
void			ft_stkadd_back(t_stack **stack, t_stack *new);
/*Ordenación*/
int				search_less_mv(t_algorithm_data *alg, t_stack **a, t_stack **b);
void			search_less_pos(t_stack **a, t_stack **b, t_algorithm_data *al);
int				order_3(t_stack **a, int min, int max);
void			order(t_parameters *parameters);
/*Posicionamiento*/
void			make_position(t_algorithm_data *alg, t_parameters *param);
void			make_pos_together(t_algorithm_data *alg, t_parameters *param);
/*Utiles de algoritmia*/
int				ft_min(t_stack **b);
int				ft_min_array(int *array);
int				ft_max(t_stack **b);
int				ft_max_int(int a, int b);
int				ft_last(t_stack **b);
/*Programa*/
void			start_algorithm(t_algorithm_data *algoritmia, t_parameters *p);
void			push_swap(t_parameters *parameters, char **arguments);
t_parameters	*ft_init_parameters(t_parameters *parameters);
/*reordenacion final*/
void			reorder(t_stack **a, int min, char c);
void			complete_stack(t_parameters *param);
void			free_stack(t_stack **a);
/*Funciones utiles*/
void			ft_error(int num);
int				ft_len(char *s);
int				ft_atoi(const char *str);
#endif
