/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:10:13 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/04 22:53:29 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_line(t_utils *u, char *str)
{
	t_togs	*t;
	t_num	*nb;
	int		match_important;
	int		match_objects;
	int		match_lights;

	t = &u->t;
	nb = &u->nb;
	match_important = check_important(u, str);
	match_objects = check_objects(u, str);
	match_lights = check_lights(u, str);
	if (match_important != 1 && t->optional == 0)
		ft_error_parse(u, str, "Not enough options to even start a window!");
	if (match_objects == ERROR || match_important == ERROR ||
		match_lights == ERROR || u->scene != 1)
		ft_error_parse(u, str, "Wrong number of options!");
}

void	parse_through_file(t_utils *u, char *str)
{
	t_str *s;

	s = &u->s;
	while (*s->buf != '\0')
	{
		if (ft_str_new_line_len(s->buf) > 1024)
			ft_error_parse(u, str, "Line is too long!");
		ft_cpy_word(str, s->buf);
		if (ft_strcmp(str, "") == 0)
		{
			while (!(ft_isalnum(*s->buf)) && *s->buf != '\0')
				s->buf++;
			ft_cpy_word(str, s->buf);
		}
		check_line(u, str);
		while (*s->buf != '\n' && *s->buf != '\0')
			s->buf++;
	}
}

void	parse(t_utils *u, char *av)
{
	t_str	*s;
	char	*str;
	int		fd;
	int		size;

	if (!(str = (char *)ft_memalloc(2048)))
		ft_error("First allocation failed!");
	if (init_parse(u) == ERROR)
		ft_error_parse(u, str, "Failed to malloc strings needed!");
	s = &u->s;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error_parse(u, str, "Failed to open file!\nusage: ./rtv1 [file]");
	size = read(fd, s->buf, BUFF_SIZE);
	run_basic_checks(u, str, size);
	(void)close(fd);
	parse_through_file(u, str);
	free_strings(u, str);
}
