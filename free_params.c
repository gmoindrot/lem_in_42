/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:13:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/17 17:14:08 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_free_params(t_params **params)
{
	ft_strdel(&((*params)->error_type));
	ft_strdel(&((*params)->path_start_end));
	free(*params);
}
