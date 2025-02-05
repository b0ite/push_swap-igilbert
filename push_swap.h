/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:58:00 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 12:27:16 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_tab
{
	int				value;
	int				index;
	struct s_tab	*next;
}	t_tab;

t_tab	*fill_a(char **av);
void	print_tab(t_tab *a);
int		full_check(t_tab *a);
void	free_split(char **split);
t_tab	*free_tab(t_tab *a);
int		check_sorted(t_tab *a);
int		check_numbers(t_tab *a);
int		check_double(t_tab *a);
void	index_tab(t_tab *a);
int		tab_size(t_tab *a);
int		biggest_index(t_tab *a);
void	ra(t_tab **a);
void	rb(t_tab **b);
void	sa(t_tab *a);
void	sb(t_tab *b);
void	ss(t_tab *a, t_tab *b);
void	pa(t_tab **a, t_tab **b);
void	pb(t_tab **a, t_tab **b);
void	rrr(t_tab **a, t_tab **b);
void	rra(t_tab **a);
void	rrb(t_tab **b);
void	rr(t_tab **a, t_tab **b);
int		first_index(t_tab *a);
int		second_index(t_tab *a);
int		third_index(t_tab *a);
void	sort_three(t_tab **a);
void	sort_five(t_tab **a, t_tab **b);
void	sort_stack(t_tab **a, t_tab **b);
int		has_nums_in_range(t_tab *a, int min, int max);
int		find_min_position(t_tab *a);
int		find_max_position(t_tab *b);
void	find_max_and_push(t_tab **b, t_tab **a);
int		get_chunk_size(int size);
void	push_num_in_range(t_tab **a, t_tab **b, int min, int max);
void	process_chunk(t_tab **a, t_tab **b, int min, int max);

#endif