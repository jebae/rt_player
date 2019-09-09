/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:36:57 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/09 16:57:44 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_important_camera(t_utils *u, t_cam *cam, char *str)
{
	t_str	*s;
	t_num	*nb;

	s = &u->s;
	nb = &u->nb;
	if (ft_strcmp(s->word, "location") == 0)
	{
		nb->location++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &cam->pos, s->str);
		check_for_duplicates(u, str, nb->location);
	}
	if (ft_strcmp(s->word, "focus") == 0)
	{
		nb->focus++;
		if (check_for_number(s->str))
			handle_4vec_number(u, &cam->focus, s->str);
		check_for_duplicates(u, str, nb->focus);
	}
}

void	parse_camera(t_utils *u, char *str)
{
	t_cam	*cam;
	t_str	*s;

	cam = &u->cam;
	s = &u->s;
	while (*s->buf != '\0' && *s->buf != '}')
	{
		ft_strnlinecpy(s->str, s->buf);
		ft_cpy_word(s->word, s->str);
		check_important_camera(u, cam, str);
		while (ft_isalnum(*s->buf) || is_skippable_char(*s->buf))
			s->buf++;
		if (*s->buf == '\n')
			s->buf++;
	}
	check_number_of_all_cam(u, str);
}
