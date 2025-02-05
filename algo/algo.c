/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:23:49 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:03:38 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_tab **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(*a);
	else if (first > second && second > third)
	{
		sa(*a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(*a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_five(t_tab **a, t_tab **b)
{
	int	size;
	int	min_pos;

	size = tab_size(*a);
	while (size > 3)
	{
		min_pos = find_min_position(*a);
		if (min_pos <= size / 2)
		{
			while (min_pos-- > 0)
				ra(a);
		}
		else
		{
			while (min_pos++ < size)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	return (30);
}

void	push_num_in_range(t_tab **a, t_tab **b, int min, int max)
{
	int	num;

	num = first_index(*a);
	if (num >= min && num < max)
	{
		pb(a, b);
		if (first_index(*b) < (min + max) / 2)
			rb(b);
	}
	else
		ra(a);
}

void	process_chunk(t_tab **a, t_tab **b, int min, int max)
{
	while (has_nums_in_range(*a, min, max))
		push_num_in_range(a, b, min, max);
}
