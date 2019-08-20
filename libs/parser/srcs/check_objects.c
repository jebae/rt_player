/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:11:44 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 18:37:28 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// TODO: split this into functions
int		check_objects(t_utils *u, char *str)
{
	if (ft_strcmp(str, "objects") == 0)
	{
		u->optional = 1;
		return (1);
	}
	if (ft_strcmp(str, "sphere") == 0)
	{
		u->index++;
		if (u->index > 19)
			return (ERROR);
		// TODO(almoraru): parse important options in here!!!!!! else return big boy ERROR
		puts("SPHERE");
		parse_sphere(u);
		return (1);
	}
	if (ft_strcmp(str, "cylinder") == 0)
	{
		u->index++;
		if (u->index > 19)
			return (ERROR);
		puts("CYLINDER");
		parse_cylinder(u);
		return (1);
	}
	if (ft_strcmp(str, "plane") == 0)
	{
		u->index++;
		if (u->index > 19)
			return (ERROR);
		puts("PLANE");
		parse_plane(u);
		return (1);
	}
	if (ft_strcmp(str, "cone") == 0)
	{
		u->index++;
		if (u->index > 19)
			return (ERROR);
		puts("CONE");
		parse_cone(u);
		return (1);
	}
	return (0);
}
