/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_optional.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 21:09:29 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/04 23:02:46 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_optional_light_properties(t_utils *u
								, t_light_commons *att, char *str)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "intensity") == 0)
	{
		nb->intensity++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &att->intensity, s->str);
		check_for_duplicates_optional(u, str, nb->intensity);
	}
}

void	check_optional_properties2(t_utils *u, t_object_commons *att, char *str)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "transparency") == 0)
	{
		nb->transparency++;
		if (check_for_number(s->str))
			handle_float_number(u, s->str, &att->transparency);
		check_for_duplicates_object_optional(u, att, str, nb->transparency);
	}
	if (ft_strcmp(s->word, "ior") == 0)
	{
		nb->ior++;
		if (check_for_number(s->str))
			handle_float_number(u, s->str, &att->ior);
		check_for_duplicates_object_optional(u, att, str, nb->ior);
	}
}

void	check_optional_properties(t_utils *u, t_object_commons *att, char *str)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "specular_alpha") == 0)
	{
		nb->specular_alpha++;
		if (check_for_number(s->str))
			handle_int_number(u, s->str, &att->specular_alpha);
		check_for_duplicates_object_optional(u, att, str, nb->specular_alpha);
	}
	if (ft_strcmp(s->word, "reflectivity") == 0)
	{
		nb->reflectivity++;
		if (check_for_number(s->str))
			handle_float_number(u, s->str, &att->reflectivity);
		check_for_duplicates_object_optional(u, att, str, nb->reflectivity);
	}
	check_optional_properties2(u, att, str);
}
