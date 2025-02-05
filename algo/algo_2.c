/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:18:48 by igilbert          #+#    #+#             */
/*   Updated: 2025/02/05 13:03:33 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_into_chunks(t_tab **a, t_tab **b, int size)
{
	int	chunk_size;
	int	min;
	int	max;
	int	i;

	chunk_size = get_chunk_size(size);
	min = 0;
	max = chunk_size;
	i = 0;
	while (i < (size + chunk_size - 1) / chunk_size)
	{
		process_chunk(a, b, min, max);
		min += chunk_size;
		max += chunk_size;
		i++;
	}
	while (tab_size(*a) > 0)
		pb(a, b);
}

void	process_towards_b(t_tab **a, t_tab **b, int min, int max)
{
	while (*a && has_nums_in_range(*a, min, max))
	{
		if ((*a)->index >= min && (*a)->index < max)
		{
			pb(a, b);
			if ((*b)->index < (min + max) / 2)
				rb(b);
		}
		else
			ra(a);
	}
}

void	move_back_to_a(t_tab **a, t_tab **b)
{
	int	max_pos;
	int	size_b;

	while (*b)
	{
		max_pos = find_max_position(*b);
		size_b = tab_size(*b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos > 0)
			{
				rb(b);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size_b)
			{
				rrb(b);
				max_pos++;
			}
		}
		pa(a, b);
	}
}

void	chunk_sort(t_tab **a, t_tab **b)
{
	int	size;
	int	chunk_size;
	int	min;
	int	max;

	size = tab_size(*a);
	if (size <= 100)
		chunk_size = size / 5;
	else
		chunk_size = size / 11;
	min = 0;
	max = chunk_size;
	while (*a)
	{
		process_towards_b(a, b, min, max);
		min += chunk_size;
		max += chunk_size;
	}
	move_back_to_a(a, b);
}

void	sort_stack(t_tab **a, t_tab **b)
{
	int	size;

	size = tab_size(*a);
	if (size <= 1 || check_sorted(*a))
		return ;
	else if (size == 2)
	{
		if (first_index(*a) > second_index(*a))
			sa(*a);
	}
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		chunk_sort(a, b);
}
