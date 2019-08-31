/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:11:44 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/31 15:23:22 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_objects2(t_utils *u, char *str)
{
	if (ft_strcmp(str, "plane") == 0)
	{
		check_and_increase_object_index(u, str);
		parse_plane(u, str);
		return (1);
	}
	if (ft_strcmp(str, "cone") == 0)
	{
		check_and_increase_object_index(u, str);
		parse_cone(u, str);
		return (1);
	}
	return (0);
}

int		check_objects(t_utils *u, char *str)
{
	t_togs	*t;

	t = &u->t;
	if (ft_strcmp(str, "objects") == 0)
	{
		t->optional = 1;
		return (1);
	}
	if (ft_strcmp(str, "sphere") == 0)
	{
		check_and_increase_object_index(u, str);
		parse_sphere(u, str);
		return (1);
	}
	if (ft_strcmp(str, "cylinder") == 0)
	{
		check_and_increase_object_index(u, str);
		parse_cylinder(u, str);
		return (1);
	}
	if (check_objects2(u, str))
		return (1);
	return (0);
}
