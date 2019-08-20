/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:15:35 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 18:42:11 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		init_parse(t_utils *u)
{
	if (!(u->buf = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (ERROR);
	if (!(u->sub_nb = (char *)ft_memalloc(1024)))
		return (ERROR);
	if (!(u->str = (char *)ft_memalloc(2048)))
		return (ERROR);
	if (!(u->number = (char *)ft_memalloc(1024)))
		return (ERROR);
	if (!(u->word = (char *)ft_memalloc(1024)))
		return (ERROR);
	u->index = -1;
	u->light_index = -1;
	return (GOOD);
}
