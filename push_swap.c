/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:04:58 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 13:12:48 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **list)
{
	int	max;
	int	max_bit;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max = ft_lstsize(list) - 1;
	max_bit = 0;
	while (max >> max_bit)
		max_bit++;
	
}