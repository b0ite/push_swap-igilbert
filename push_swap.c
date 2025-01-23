/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:04:58 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 18:25:06 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_max_bit(t_list **list)
{
	int	max_bit;
	int	max;

	max_bit = 0;
	max = *(int *)ft_lstlast(*list)->content;
	printf("%d\n", max);
	while (max >> max_bit)
		max_bit++;
	return (max_bit);
}

void	push_swap(t_list **list_a)
{
	int	max_bit;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max_bit = get_max_bit(list_a);
	while (i < max_bit)
	{
		while (j < ft_lstsize(*list_a))
		{
			if (((*((int *)(*list_a)->content) >> i) & 1 == 1))
				ft_ra(list_a);
			else
				ft_pb(list_a, *list_a);
		}
	}
	
}
int	main(void)
{
	t_list *list = NULL;
	t_list *new_node;

	int *value;

	value = malloc(sizeof(int));
	*value = 8;
	new_node = ft_lstnew(value);
	ft_lstadd_back(&list, new_node);

	value = malloc(sizeof(int));
	*value = 10;
	new_node = ft_lstnew(value);
	ft_lstadd_back(&list, new_node);

	value = malloc(sizeof(int));
	*value = 20000;
	new_node = ft_lstnew(value);
	ft_lstadd_back(&list, new_node);

	int max_bit = get_max_bit(&list);
	printf("Max bit: %d\n", max_bit);//15

	ft_lstclear(&list, free);
	return 0;
}