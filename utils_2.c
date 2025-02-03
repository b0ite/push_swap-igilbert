/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:45:18 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/03 11:51:31 by igilbert         ###   ########.fr       */
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