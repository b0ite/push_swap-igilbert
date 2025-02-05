/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:57:57 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:03:52 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_tab **a, t_tab **b)
{
	t_tab	*tmp;
	t_tab	*tmp2;
	t_tab	*tmp3;
	t_tab	*tmp4;

	if (!*a || !(*a)->next || !*b || !(*b)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *a;
	*a = tmp2;
	tmp3 = *b;
	while (tmp3->next->next)
		tmp3 = tmp3->next;
	tmp4 = tmp3->next;
	tmp3->next = NULL;
	tmp4->next = *b;
	*b = tmp4;
	ft_printf("rrr\n");
}
