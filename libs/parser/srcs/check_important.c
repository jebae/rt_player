/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_important.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:03:41 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 18:04:12 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_important(t_utils *u, char *str)
{
	if ((ft_strcmp(str, "scene")) == 0)
	{
		u->nb_scene++;
		return (1);
	}
	if ((ft_strcmp(str, "camera")) == 0)
	{
		u->nb_cam++;
		if (u->nb_cam != 1)
			return (ERROR);
		parse_camera(u);
		return (1);
	}
	return (0);
}