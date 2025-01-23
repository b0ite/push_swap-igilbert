/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:57:37 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 17:59:04 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **list_a)
{
	t_list	*cell_list_a;
	t_list	*last_cell_list_a;

	if (!*list_a || !(*list_a)->next)
		return (0);
	cell_list_a = *list_a;
	*list_a = (*list_a)->next;
	last_cell_list_a = ft_lstlast(*list_a);
	last_cell_list_a->next = cell_list_a;
	cell_list_a->next = NULL;
	write(1, "ra\n", 3);
	return (1);
}

int	ft_rb(t_list **list_b)
{
	t_list	*cell_list_b;
	t_list	*last_cell_list_b;

	if (!*list_b || !(*list_b)->next)
		return (0);
	cell_list_b = *list_b;
	*list_b = (*list_b)->next;
	last_cell_list_b = ft_lstlast(*list_b);
	last_cell_list_b->next = cell_list_b;
	cell_list_b->next = NULL;
	write(1, "rb\n", 3);
	return (1);
}