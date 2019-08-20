/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:10:13 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/18 19:27:40 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		check_line(t_utils *u, char *str)
{
	int match_important;
	int match_objects;
	int match_lights;

	match_important = 0;
	match_objects = 0;
	match_lights = 0;
	match_important = check_important(u, str);
	match_objects = check_objects(u, str);
	match_lights = check_lights(u, str);
	printf("match ? = %d\n", match_important);
	if (match_important != 1 && u->optional == 0)
	{
		printf("string = %s\n", str);
		return (ERROR);
	}
	if (match_objects == ERROR || match_important == ERROR ||
		match_lights == ERROR || u->nb_scene != 1)
		return (ERROR);
	return (GOOD);
}

int		parse_through_file(t_utils *u, char *str)
{
	// TODO(almoraru): CHECK THAT SCENE IS THE FIRST WORD OF THE FILE. CAMERA IS SECOND ETC...
	while (*u->buf != '\0')
	{
		if (ft_str_new_line_len(u->buf) > 1024)
			return (ERROR);
		ft_cpy_word(str, u->buf);
		if (ft_strcmp(str, "") == 0)
		{
			while (!(ft_isalnum(*u->buf)) && *u->buf != '\0')
				u->buf++;
			ft_cpy_word(str, u->buf);
		}
		printf("---------\nLINE COPIED !!\n%s\n---------\n", str);
		if ((check_line(u, str) == ERROR))
			return (ERROR);
		while (*u->buf != '\n' && *u->buf != '\0')
			u->buf++;
	}
	return (GOOD);
}

int		parse(t_utils *u, char *av)
{
	int		fd;
	char	*str;

	if (!(str = (char *)ft_memalloc(2048)))
		return (ERROR);
	if (init_parse(u) == ERROR)
		return (ERROR);
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_error("Failed to open file!\nusage: ./RTv1 [file]");
	u->size = read(fd, u->buf, BUFF_SIZE);
	if (u->size >= BUFF_SIZE)
		return (ERROR);
	(void)close(fd);
	if ((pre_check(u->buf)) == ERROR)
		return (ERROR);
	if ((check_basics(u)) == ERROR)
		return (ERROR);
	if (u->nb_bracket_o != u->nb_bracket_c)
	{
		printf("Brackets = open %d | closed %d\n", u->nb_bracket_o, u->nb_bracket_c);
		return (ERROR);
	}
	if (parse_through_file(u, str) == ERROR)
		return (ERROR);
	printf("SO THE NUMBER OF OBJETCS = %d\nAND NUMBER OF LIGHTS = %d\n", u->index + 1, u->light_index + 1);
	return (GOOD);
}
