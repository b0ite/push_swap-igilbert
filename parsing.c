/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:01:44 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 11:50:02 by igilbert         ###   ########.fr       */
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
		if (!ft_atoi(split[i]))
		{
			ft_printf("Error : %s not an integer\n", split[i]);
			free_split(split);
			return (NULL);
		}
		a = add_back(a, ft_atoi(split[i]));
		i++;
	}
	index_tab(a);
	free_split(split);
	if (!full_check(a))
		return (free_tab(a));
	return (a);
}
