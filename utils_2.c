/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:45:18 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/04 11:22:36 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab	*free_tab(t_tab *a)
{
	t_tab	*current;
	t_tab	*next;

	current = a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	return (NULL);
}

int	check_sorted(t_tab *a)
{
	t_tab	*current;

	current = a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	tab_size(t_tab *a)
{
	t_tab	*current;
	int		size;

	size = 0;
	current = a;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}