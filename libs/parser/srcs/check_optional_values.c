/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_optional_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:43:27 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/04 23:19:26 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_for_duplicates_optional(t_utils *u, char *str, int nb)
{
	if (nb > 1)
		ft_error_parse(u, str, "No duplicates allowed!");
}

void	check_and_change_attribute(t_utils *u, t_object_commons *att)
{
	t_num		*nb;

	nb = &u->nb;
	if (nb->reflectivity == 0)
		att->reflectivity = 0.2f;
	if (nb->transparency == 0)
		att->transparency = 0.2f;
	if (nb->specular_alpha == 0)
		att->specular_alpha = 50;
	if (nb->ior == 0)
		att->ior = 1.5f;
}
