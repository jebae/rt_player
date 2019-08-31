/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almoraru <almoraru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:12:24 by almoraru          #+#    #+#             */
/*   Updated: 2019/08/31 14:41:22 by almoraru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	free_strings(t_utils *u, char *str)
{
	t_str	*s;

	s = &u->s;
	if (s->sub_nb != NULL)
		free(s->sub_nb);
	if (s->str != NULL)
		free(s->str);
	if (s->word != NULL)
		free(s->word);
	if (str != NULL)
		free(str);
}
