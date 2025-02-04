/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:12:38 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/04 11:34:23 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tab *a)
{
	int	tmp;

	if (!a || !a->next)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	ft_printf("sa\n");
}

void	sb(t_tab *b)
{
	int	tmp;

	if (!b || !b->next)
		return ;
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	ft_printf("sb\n");
}

void	ss(t_tab *a, t_tab *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_tab **a, t_tab **b)
{
	t_tab	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("pa\n");
}

void	pb(t_tab **a, t_tab **b)
{
	t_tab	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("pb\n");
}
