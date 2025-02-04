/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:34:11 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/04 12:01:51 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_tab **a)
{
	t_tab	*tmp;
	t_tab	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_tab **b)
{
	t_tab	*tmp;
	t_tab	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	tmp2 = *b;
	*b = (*b)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	ft_printf("rb\n");
}
