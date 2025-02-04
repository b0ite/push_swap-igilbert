/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:45:18 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/04 12:01:55 by igilbert         ###   ########.fr       */
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

int	biggest_index(t_tab *a)
{
	t_tab	*current;
	int		biggest;

	if (!a)
		return (0);
	current = a;
	biggest = current->index;
	while (current)
	{
		if (current->index > biggest)
			biggest = current->index;
		current = current->next;
	}
	return (biggest);
}
