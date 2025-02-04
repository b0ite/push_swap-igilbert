/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:58:00 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/04 11:33:44 by igilbert         ###   ########.fr       */
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

void	print_tab(t_tab *a);
int		full_check(t_tab *a);
void	free_split(char **split);
t_tab	*free_tab(t_tab *a);
int		check_sorted(t_tab *a);
int		tab_size(t_tab *a);
void	ra(t_tab **a);
void	rb(t_tab **b);
void	sa(t_tab *a);
void	sb(t_tab *b);
void	ss(t_tab *a, t_tab *b);
void	pa(t_tab **a, t_tab **b);
void	pb(t_tab **a, t_tab **b);

#endif