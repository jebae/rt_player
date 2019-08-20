/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_optional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:09:29 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 19:23:30 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_optional_light_properties(t_utils *u, t_light_commons *att)
{
	if (ft_strcmp(u->word, "intensity") == 0)
	{
		if (check_for_number(u->str))
			handle_4vec_number(u, &att->intensity, u->str);
	}
}

void	check_optional_properties(t_utils *u, t_object_commons *att)
{
	if (ft_strcmp(u->word, "specular_alpha") == 0)
	{
		if (check_for_number(u->str))
			handle_int_number(u, att->specular_alpha, u->str);
	}
	if (ft_strcmp(u->word, "reflectivity") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, att->reflectivity, u->str);
	}
	if (ft_strcmp(u->word, "transparency") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, att->transparency, u->str);
	}
	if (ft_strcmp(u->word, "ior") == 0)
	{
		if (check_for_number(u->str))
			handle_float_number(u, att->ior, u->str);
	}
}
