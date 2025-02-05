/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:46:45 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 12:53:31 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;

	if (ac < 2)
		return (0);
	a = fill_a(av);
	b = NULL;
	if (!a)
		return (0);
	if (!check_numbers(a) || !check_double(a))
	{
		free_tab(a);
		return (0);
	}
	index_tab(a);
	sort_stack(&a, &b);
	free_tab(a);
	free_tab(b);
	return (0);
}
