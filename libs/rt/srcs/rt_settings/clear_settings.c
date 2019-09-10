/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:44:27 by jebae             #+#    #+#             */
/*   Updated: 2019/09/10 17:44:28 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		clear_rt_settings(t_rt_settings *settings)
{
	if (settings->objects_buf != NULL)
		ft_memdel((void **)&(settings->objects_buf));
	if (settings->lights_buf != NULL)
		ft_memdel((void **)&(settings->lights_buf));
}
