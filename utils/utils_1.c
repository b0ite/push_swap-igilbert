/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:14:12 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:03:57 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	check_numbers(t_tab *a)
{
	t_tab	*current;

	current = a;
	while (current)
	{
		if (current->value > 2147483647 || current->value < -2147483648)
		{
			ft_printf("Error : %d not an integer\n", current->value);
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	check_double(t_tab *a)
{
	t_tab	*current;
	t_tab	*compare;

	current = a;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
			{
				ft_printf("Error : %d twice\n", current->value);
				return (0);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (1);
}

int	full_check(t_tab *a)
{
	if (!check_double(a))
		return (0);
	if (!check_numbers(a))
		return (0);
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
