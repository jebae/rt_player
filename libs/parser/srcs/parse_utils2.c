/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:03:00 by almoraru          #+#    #+#             */
/*   Updated: 2019/09/09 16:47:50 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	run_basic_checks(t_utils *u, char *str, int size)
{
	t_num	*nb;
	t_str	*s;

	nb = &u->nb;
	s = &u->s;
	if (size > BUFF_SIZE)
		ft_error_parse(u, str, "File is too big!");
	if ((pre_check(s->buf)) == ERROR)
		ft_error_parse(u, str, "Are you even trying?");
	if ((check_basics(u)) == ERROR)
		ft_error_parse(u, str, "Basic checks failed!");
	if (nb->bracket_o != nb->bracket_c)
		ft_error_parse(u, str, "Uneven number of open and closed brackets!");
}
