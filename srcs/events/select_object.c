/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:46:37 by jebae             #+#    #+#             */
/*   Updated: 2019/09/02 18:46:39 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_player.h"

void		key_left_bracket(t_dispatcher *dispatcher)
{
	if (dispatcher->object_index == 0)
	{
		dispatcher->object_index = dispatcher->settings->num_objects - 1;
		return ;
	}
	(dispatcher->object_index)--;
}

void		key_right_bracket(t_dispatcher *dispatcher)
{
	(dispatcher->object_index)++;
	dispatcher->object_index %= dispatcher->settings->num_objects;
}
