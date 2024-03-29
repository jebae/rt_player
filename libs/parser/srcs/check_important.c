/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_important.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:03:41 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/30 16:33:37 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_important(t_utils *u, char *str)
{
	t_num	*nb;

	nb = &u->nb;
	if ((ft_strcmp(str, "scene")) == 0)
	{
		u->scene++;
		return (1);
	}
	if ((ft_strcmp(str, "camera")) == 0)
	{
		nb->cam++;
		check_for_duplicates(u, str, nb->cam);
		parse_camera(u, str);
		return (1);
	}
	return (0);
}
