/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:28:17 by igilbert          #+#    #+#             */
/*   Updated: 2024/12/19 17:09:07 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tab_add_back(t_tab **alst, t_tab *new)
{
	t_tab	*last;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	last = *alst;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	process_input(char *input, t_tab **stack_a)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(input, ' ');
	while (split[i])
	{
		is_digit(split[i]);
		tab_add_back(stack_a, tab_new(ft_atoi(split[i])));
		i++;
	}
}
