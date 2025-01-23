/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:41:10 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 18:31:28 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

void	ft_free_split(char **split);
t_list	**errlist(t_list **lst, void (*del)(void *));
void	fill_with_zero(int *array, int size);
int		*intify(char **split, int *size);
t_list	**process_input(char *input);
t_list	**listify(int *int_array, int size);
int		ft_ra(t_list **list_a);
int		ft_rb(t_list **list_b);
int		ft_pa(t_list **list_a, t_list *list_b);
int		ft_pb(t_list **list_b, t_list *list_a);
void	push_swap(t_list **list_a, t_list **list_b);

#endif