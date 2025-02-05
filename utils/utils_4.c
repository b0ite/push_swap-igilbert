/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:45:18 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:04:08 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_max_position(t_tab *b)
{
	t_tab	*current;
	int		max;
	int		max_pos;
	int		current_pos;

	current = b;
	max = current->value;
	max_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}
