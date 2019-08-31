/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:36:22 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/31 14:44:49 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_lights(t_utils *u, char *str)
{
	t_togs *t;

	t = &u->t;
	if (ft_strcmp(str, "lights") == 0)
	{
		t->optional = 1;
		return (1);
	}
	if (ft_strcmp(str, "distant") == 0)
	{
		check_and_increase_light_index(u, str);
		parse_distant_light(u, str);
		return (1);
	}
	if (ft_strcmp(str, "spherical") == 0)
	{
		check_and_increase_light_index(u, str);
		parse_spherical_light(u, str);
		return (1);
	}
	return (0);
}
