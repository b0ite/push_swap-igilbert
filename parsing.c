/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:01:44 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/18 00:54:18 by igilbert         ###   ########.fr       */
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

t_tab	*one_arv(t_tab *a, char **av)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(av[1], ' ');
	while (split[i])
	{
		if (!ft_atoi(split[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free_split(split);
			return (NULL);
		}
		a = add_back(a, ft_atoi(split[i]));
		i++;
	}
	index_tab(a);
	free_split(split);
	return (a);
}

t_tab	*fill_a(char **av)
{
	t_tab	*a;
	int		i;

	i = 0;
	a = NULL;
	if (ft_strchr(av[1], ' '))
		a = one_arv(a, av);
	else
	{
		while (av[i + 1])
		{
			if (!ft_atoi(av[i + 1]) && av[i + 1][0] != '0')
			{
				ft_putstr_fd("Error\n", 2);
				return (free_tab(a));
			}
			a = add_back(a, ft_atoi(av[i + 1]));
			i++;
		}
	}
	if (!full_check(a))
		return (free_tab(a));
	return (a);
}
