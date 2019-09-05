/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 18:15:35 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/05 21:33:07 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		init_parse(t_utils *u)
{
	t_str	*s;
	t_index	*index;

	s = &u->s;
	index = &u->i;
	if (!(s->buf = (char *)ft_memalloc(BUFF_SIZE)))
		return (ERROR);
	if (!(s->sub_nb = (char *)ft_memalloc(1024)))
		return (ERROR);
	if (!(s->str = (char *)ft_memalloc(2048)))
		return (ERROR);
	if (!(s->number = (char *)ft_memalloc(1024)))
		return (ERROR);
	if (!(s->word = (char *)ft_memalloc(1024)))
		return (ERROR);
	index->object = -1;
	index->light = -1;
	return (GOOD);
}
