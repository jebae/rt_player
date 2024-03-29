/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 15:17:49 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/09 17:37:40 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_and_increase_object_index(t_utils *u, char *str)
{
	t_index *index;

	index = &u->i;
	index->object++;
	if (index->object > 19)
		ft_error_parse(u, str, "Too many objects in the file!");
}

void	check_and_increase_light_index(t_utils *u, char *str)
{
	t_index *index;

	index = &u->i;
	index->light++;
	if (index->light > 4)
		ft_error_parse(u, str, "Too many lights in the file!");
}

void	check_for_duplicates(t_utils *u, char *str, int nb)
{
	if (nb != 1)
		ft_error_parse(u, str, "No duplicates allowed!");
}

void	check_for_duplicates_optional(t_utils *u
											, char *str, int nb)
{
	if (nb > 1)
		ft_error_parse(u, str, "No duplicates allowed!");
}

void	check_number_of_all_cam(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->location != 1 || nb->focus != 1)
		ft_error_parse(u, str, "Wrong camera parameters!");
	ft_bzero(nb, 88);
}
