/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:02:15 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:04:04 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	has_nums_in_range(t_tab *a, int min, int max)
{
	t_tab	*current;

	if (!a)
		return (0);
	current = a;
	while (current)
	{
		if (current->index >= min && current->index < max)
			return (1);
		current = current->next;
	}
	return (0);
}

int	find_min_position(t_tab *a)
{
	t_tab	*current;
	int		min;
	int		min_pos;
	int		current_pos;

	current = a;
	min = current->value;
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

void	find_max_and_push(t_tab **b, t_tab **a)
{
	int	max_pos;
	int	size;

	size = tab_size(*b);
	max_pos = find_max_position(*b);
	while (max_pos > 0)
	{
		if (max_pos <= size / 2)
			rb(b);
		else
			rrb(b);
		max_pos = find_max_position(*b);
	}
	pa(a, b);
}

int	second_index(t_tab *a)
{
	t_tab	*current;

	current = a;
	while (current->index != 1)
		current = current->next;
	return (current->value);
}

int	third_index(t_tab *a)
{
	t_tab	*current;

	current = a;
	while (current->index != 2)
		current = current->next;
	return (current->value);
}
