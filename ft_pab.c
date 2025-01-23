/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:57:27 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 19:20:36 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_list **list_a, t_list *cell_list_b)
{
	t_list	*cell_list_a;
	void	*content;

	if (!cell_list_b)
		return (0);
	content = cell_list_b->content;
	cell_list_a = ft_lstnew(content);
	if (!cell_list_a)
		return (0);
		
	ft_lstadd_front(list_a, cell_list_a);
	free(cell_list_b);
	write(1, "pa\n", 3);
	return (1);
}

int	ft_pb(t_list **list_b, t_list *cell_list_a)
{
	t_list	*cell_list_b;
	void	*content;

	if (!cell_list_a)
		return (0);
	content = cell_list_a->content;
	cell_list_b = ft_lstnew(content);
	if (!cell_list_b)
		return (0);
		
	ft_lstadd_front(list_b, cell_list_b);
	free(cell_list_a);
	write(1, "pb\n", 3);
	return (1);
}