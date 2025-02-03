/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:01:44 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/03 11:15:42 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab	*add_back(t_tab *lst, int value)
{
	t_tab	*new;
	t_tab	*current;

	new = malloc(sizeof(t_tab));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	if (!lst)
		return (new);
	current = lst;
	while (current->next)
		current = current->next;
	current->next = new;
	return (lst);
}

void	index_tab(t_tab *a)
{
	t_tab	*current;
	t_tab	*compare;
	int		size;

	current = a;
	while (current)
	{
		size = 0;
		compare = a;
		while (compare)
		{
			if (current->value > compare->value)
				size++;
			compare = compare->next;
		}
		current->index = size;
		current = current->next;
	}
}

t_tab	*check_double(t_tab *a)
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
				ft_printf("Error\n");
				return (NULL);
			}
			compare = compare->next;
		}
		current = current->next;
	}
	return (a);
}

t_tab	*fill_a(char **av)
{
	t_tab	*a;
	int		i;
	char	**split;

	i = 0;
	a = NULL;
	split = ft_split(av[1], ' ');
	while (split[i])
	{
		a = add_back(a, ft_atoi(split[i]));
		i++;
	}
	index_tab(a);
	if (!check_double(a))
		return (NULL);
	return (a);
}

int	main(int ac, char **av)
{
	t_tab	*a;

	if (ac == 2)
	{
		a = fill_a(av);
		print_tab(a);
	}
	return (0);
}
