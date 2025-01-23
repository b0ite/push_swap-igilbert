/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:57:27 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 17:50:51 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pa(t_list **list_a, t_list *cell_list_b)
{
	t_list	*cell_list_a;

	if (!cell_list_b)
		return (0);
	cell_list_a = ft_lstnew(cell_list_b->content);
	if (!cell_list_a)
		return (0);
	ft_lstadd_front(list_a, cell_list_a);
	ft_lstdelone(cell_list_b, free);
	write(1, "pa\n", 3);
	return (1);
}

int	ft_pb(t_list **list_b, t_list *cell_list_a)
{
	t_list	*cell_list_b;

	if (!cell_list_a)
		return (0);
	cell_list_b = ft_lstnew(cell_list_a->content);
	if (!cell_list_b)
		return (0);
	ft_lstadd_front(list_b, cell_list_b);
	ft_lstdelone(cell_list_a, free);
	write(1, "pb\n", 3);
	return (1);
}
