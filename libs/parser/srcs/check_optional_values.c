/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_optional_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:43:27 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 21:16:51 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_and_change_attribute(t_utils *u, t_object_commons *att)
{
	t_num		*nb;

	nb = &u->nb;
	if (nb->reflectivity == 0)
	{
		ft_putendl("No reflectivity found, going with default!");
		att->reflectivity = 0.2f;
	}
	if (nb->transparency == 0)
	{
		ft_putendl("No transparency found, going with default!");
		att->transparency = 0.2f;
	}
	if (nb->specular_alpha == 0)
	{
		ft_putendl("No specular alpha found, going with default!");
		att->specular_alpha = 50;
	}
	if (nb->ior == 0)
	{
		ft_putendl("No ior found, going with default!");
		att->ior = 1.5f;
	}
}
