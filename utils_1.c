/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:14:12 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/03 11:14:58 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_tab(t_tab *a)
{
	t_tab	*current;

	current = a;
	while (current)
	{
		ft_printf("value: %d, index: %d\n", current->value, current->index);
		current = current->next;
	}
}
