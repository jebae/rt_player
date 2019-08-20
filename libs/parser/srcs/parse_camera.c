/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:36:57 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/19 17:37:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_camera(t_utils *u)
{
	t_cam *cam;

	cam = &u->cam;
	while (*u->buf != '}')
	{
		ft_strnlinecpy(u->str, u->buf);
		ft_cpy_word(u->word, u->str);
		if (ft_strcmp(u->word, "location") == 0)
		{
			if (check_for_number(u->str))
				handle_4vec_number(u, &cam->pos, u->str);
		}
		if (ft_strcmp(u->word, "focus") == 0)
		{
			if (check_for_number(u->str))
				handle_4vec_number(u, &cam->pos, u->str);
		}
		while (ft_isalnum(*u->buf) || is_skippable_char(*u->buf))
			u->buf++;
		if (*u->buf == '\n')
			u->buf++;
	}
}
