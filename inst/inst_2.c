/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:34:11 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:03:49 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	rr(t_tab **a, t_tab **b)
{
	t_tab	*tmp;
	t_tab	*tmp2;
	t_tab	*tmp3;
	t_tab	*tmp4;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	tmp = *a;
	tmp2 = *a;
	*a = (*a)->next;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
	tmp3 = *b;
	tmp4 = *b;
	*b = (*b)->next;
	while (tmp4->next)
		tmp4 = tmp4->next;
	tmp4->next = tmp3;
	tmp3->next = NULL;
	ft_printf("rr\n");
}

void	rra(t_tab **a)
{
	t_tab	*tmp;
	t_tab	*tmp2;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *a;
	*a = tmp2;
	ft_printf("rra\n");
}

void	rrb(t_tab **b)
{
	t_tab	*tmp;
	t_tab	*tmp2;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *b;
	*b = tmp2;
	ft_printf("rrb\n");
}
