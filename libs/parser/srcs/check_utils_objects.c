/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:11:50 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 21:20:45 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_number_of_all_sphere(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->r != 1 || nb->c != 1 || nb->color != 1)
		ft_error_parse(u, str, "Wrong sphere parameters!");
	ft_bzero(nb, 88);
}

void	check_number_of_all_cylinder(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->r != 1 || nb->h != 1 || nb->c != 1 || nb->v != 1
		|| nb->color != 1)
		ft_error_parse(u, str, "Wrong cylinder parameters!");
	ft_bzero(nb, 88);
}

void	check_number_of_all_plane(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->n != 1 || nb->p != 1 || nb->color != 1)
		ft_error_parse(u, str, "Wrong plane parameters!");
	ft_bzero(nb, 88);
}

void	check_number_of_all_cone(t_utils *u, char *str)
{
	t_num *nb;

	nb = &u->nb;
	if (nb->c != 1 || nb->v != 1 || nb->h != 1 || nb->theta != 1
		|| nb->color != 1)
		ft_error_parse(u, str, "Wrong cone parameters!");
	ft_bzero(nb, 88);
}
