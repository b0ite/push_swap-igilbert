/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:49 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/04 12:13:17 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_index(t_tab *a)
{
	if (!a)
		return (0);
	return (a->index);
}

void	radix_sort(t_tab **a, t_tab **b)
{
	int	max_bit;
	int	i;
	int	j;
	int	num;

	max_bit = 0;
	i = 0;
	while ((biggest_index(*a) >> max_bit) != 0)
		max_bit++;
	while (i < max_bit)
	{
		j = 0;
		while (j < (tab_size(*a) + tab_size(*b)))
		{
			num = first_index(*a);
			if (((num >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_tab	*a;
	t_tab	*b;

	if (ac < 2)
		return (0);
	a = fill_a(av);
	if (!a)
		return (0);
	b = NULL;
	//ft_printf("Initial state:\nStack A: ");
	//print_tab(a);
	//ft_printf("Stack B: ");
	//print_tab(b);
	//ft_printf("\n");
	radix_sort(&a, &b);
	//ft_printf("\nFinal state:\nStack A: ");
	//print_tab(a);
	//ft_printf("Stack B: ");
	//print_tab(b);
	free_tab(a);
	free_tab(b);
	return (0);
}
