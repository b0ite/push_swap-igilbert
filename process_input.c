/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:28:17 by igilbert          #+#    #+#             */
/*   Updated: 2025/01/23 13:32:14 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/types.h>
#include <stdio.h>

/* **************************************************************************/
char	*ft_strndup(const char *s1, int len)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (i < (size_t)len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	count_words(int c, char const *s)
{
	int	i;
	int	j;
	int	in;

	i = 0;
	j = 0;
	in = 0;
	while (s[i])
	{
		if (s[i] != (char)c && in != 1)
		{
			in = 1;
			j++;
		}
		if (s[i] == (char)c && in == 1)
			in = 0;
		i++;
	}
	return (j);
}

char	**ft_split(char const *str, char c)
{
	int		e;
	int		s;
	int		k;
	char	**res;

	s = 0;
	k = 0;
	if (!str)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(c, (char *)str) + 1));
	if (res == NULL)
		return (NULL);
	while (k < count_words(c, (char *)str) && str[s])
	{
		while (str[s] == c && str[s])
			s++;
		e = s;
		while (str[e] != c && str[e])
			e++;
		res[k] = ft_strndup((char *)str + s, e - s);
		k++;
		s = e;
	}
	res[k] = 0;
	return (res);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	long long	res;
	long long	signe;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * signe);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&(*lst)->next, del);
	if (del)
		del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;

	if (!lst)
		return (NULL);
	ret = lst;
	while (ret->next != NULL)
		ret = ret->next;
	return (ret);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
 /************************************************************************** */

void	fill_with_zero(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = 0;
		i++;
	}
}

int	*intify(char **split, int *size)
{
	int	*int_array;
	int	i;

	i = 0;
	while (split[i])
		i++;
	int_array = malloc(sizeof(int) * i);
	i = 0;
	while (split[i])
	{
		int_array[i] = ft_atoi(split[i]);
		i++;
	}
	*size = i;
	ft_free_split(split);
	return (int_array);
}

int	*positify(int *int_array, int size)
{
	int	*pos_array;
	int	i;
	int	j;

	i = 0;
	pos_array = malloc(sizeof(int) * size);
	if (!pos_array)
		return (NULL);
	fill_with_zero(pos_array, size);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (int_array[i] > int_array[j])
				pos_array[i]++;
			j++;
		}
		i++;
	}
	return (pos_array);
}

t_list	**listify(int *int_array, int size)
{
	t_list	**list;
	t_list	*new_node;
	int		i;
	int		*value;

	*list = malloc(sizeof(t_list *));
	if (!list)
		return (NULL);
	*list = NULL;
	i = 0;
	while (i < size)
	{
		value = malloc(sizeof(int));
		if (!value)
			return (errlist(list, free));
		*value = int_array[i];
		new_node = ft_lstnew(value);
		if (!new_node)
			return (errlist(list, free));
		ft_lstadd_back(list, new_node);
		i++;
	}
	return (list);
}

t_list	**process_input(char *input)
{
	int		*int_array;
	int		size;
	int		*pos_array;
	t_list	**list;

	int_array = intify(ft_split(input, ' '), &size);
	if (!int_array)
		return (NULL);
	pos_array = positify(int_array, size);
	free(int_array);
	if (!pos_array)
		return (NULL);
	list = listify(pos_array, size);
	free(pos_array);
	return (list);
}

int	main(void)
{
	char *input = "3 1 2 78 43 -688";
	t_list **list = process_input(input);
	t_list *current;

	if (!list)
	{
		printf("Error processing input.\n");
		return (1);
	}
	current = *list;
	while (current)
	{
		printf("%d\n", *(int *)current->content);
		current = current->next;
	}
	ft_lstclear(list, free);
	return (0);
}
