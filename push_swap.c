/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:04:58 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 19:02:31 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bit(t_list **list)
{
	int	max_bit;
	int	max;

	max_bit = 0;
	max = ft_lstsize(*list) - 1;
	while (max >> max_bit)
		max_bit++;
	return (max_bit);
}

void	push_swap(t_list **list_a, t_list **list_b)
{
	int	max_bit;
	int	i;
	int	j;

	i = 0;
	j = 0;
	max_bit = get_max_bit(list_a);
	ft_printf("Max bit: %d\n", max_bit);
	while (i < max_bit)
	{
		while (j < ft_lstsize(*list_a))
		{
			if (((*((int *)(*list_a)->content) >> i) & 1) == 1)
				ft_ra(list_a);
			else
				ft_pb(list_a, *list_a);
			j++;
			ft_printf("passage %d\n", j);
		}
		while (ft_lstsize(*list_b))
			ft_pa(list_a, *list_b);
		i++;
	}
}

/*
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
}*/

int	main(int arc, char **arv)
{
	t_list	**list_a;
	t_list	**list_b;

	if (arc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	list_a = process_input(arv[1]);
	t_list *temp = *list_a;
	while (temp)
	{
		ft_printf("%d ", *(int *)temp->content);//afficher les valeurs de la liste
		temp = temp->next;
	}
	ft_printf("\n");
	if (!list_a)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	list_b = malloc(sizeof(t_list *));
	if (!list_b)
	{
		write(1, "Error\n", 6);
		ft_lstclear(list_a, free);
		return (1);
	}
	*list_b = NULL;
	push_swap(list_a, list_b);
	t_list *temp2 = *list_a;
	while (temp2)
	{
		ft_printf("%d ", *(int *)temp2->content);
		temp2 = temp2->next;
	}
	ft_printf("\n");
	ft_lstclear(list_a, free);
	ft_lstclear(list_b, free);
	return (0);
}