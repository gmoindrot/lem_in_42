/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:10:43 by gmoindro          #+#    #+#             */
/*   Updated: 2019/12/02 18:46:53 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_reset_passed_flags_gasp(t_list **list)
{
	t_list *tmp;
	t_node *node;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *)tmp->content;
		if (node->passed_flag == 5 || node->passed_flag == -5)
			node->passed_flag = 5;
		else
			node->passed_flag = 0;
		node->chance_one = 0;
		tmp = tmp->next;
	}
}

int			ft_connect_start(t_list **list)
{
	t_node	*start;
	t_list	*tmp;
	int		count;

	start = ft_find_t_node_with_start(list);
	tmp = start->next;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

t_list		***ft_malloc_result(t_params **params, t_list **list)
{
	int		size;
	int		i;
	t_list	***result;

	i = -1;
	if ((*params)->ant_count >= ft_connect_start(list))
		size = ft_connect_start(list);
	else
		size = (*params)->ant_count;
	if (!(result = (t_list ***)malloc(sizeof(t_list *) * (size + 1))))
		return (NULL);
	return (result);
}

void		print_bibli(t_list ***result, int i)
{
	t_node	*node;
	t_list	*tmp;
	int		j;

	j = -1;
	ft_printf("\n");
	while (++j <= i)
	{
		node = (t_node *)((*result)[j]->content);
		ft_printf("%s ", node->name);
		tmp = (*result)[j]->next;
		while (tmp)
		{
			node = (t_node *)tmp->content;
			ft_printf("-> %s ", node->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
	}
}

void		ft_algo(t_params **params, t_list **list)
{
	t_node	*node;
	int		index;
	t_list	***result;

	index = 0;
	node = ft_find_t_node_with_start(list);
	result = ft_malloc_result(params, list);
	while (index < (*params)->ant_count && index < ft_connect_start(list)
			&& ft_bfs_gaspard(list, params, node) > 0)
	{
		if (!(result[index] = (t_list **)malloc(sizeof(t_list) * (index + 1))))
			return ;
		ft_reset_passed_flags_gasp(list);
		ft_put_bibli(list, result, index);
		index++;
	}

	int		l;
	l = -1;
	while (++l < index)
		print_bibli(&result[l], l);
}
