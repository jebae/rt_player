/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:36:22 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 19:21:19 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_lights(t_utils *u, char *str)
{
	if (ft_strcmp(str, "lights") == 0)
	{
		u->optional = 1;
		return (1);
	}
	if (ft_strcmp(str, "distant") == 0)
	{
		u->light_index++;
		if (u->light_index > 4)
			return (ERROR);
		puts("DISTANT LIGHT");
		parse_distant_light(u);
		return (1);
	}
	if (ft_strcmp(str, "spherical") == 0)
	{
		u->light_index++;
		if (u->light_index > 4)
			return (ERROR);
		puts("SPHERICAL LIGHT");
		parse_spherical_light(u);
		return (1);
	}
	return (0);
}