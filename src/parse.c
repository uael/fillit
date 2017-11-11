/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/11 18:20:40 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_u08	fillit_parse_elm(t_elm *elm, t_car const **str)
{
	t_u08	i;
	t_u08	n;
	t_car	c;

	if (ft_strlen(*str) < 20)
		return (1);
	if ((*str)[4] != '\n' || (*str)[9] != '\n' ||
		(*str)[14] != '\n' || (*str)[19] != '\n')
		return (1);
	FT_INIT(elm, t_elm);
	i = 0;
	n = 0;
	while (i < 16)
		if ((c = *(*str)++) == '#' && ++n)
			*elm |= 1 << i++;
		else if (c == '.')
			++i;
		else if (c != '\n')
			return (1);
	if (**str == '\n')
		++*str;
	return ((t_u08)(n > 4 ? 1 : 0));
}

t_u08			fillit_parse(t_ctx *ctx, t_car const *str)
{
	t_elm	elm;
	t_elm	*elms;
	t_usz	sz;

	if (!(sz = ft_strlen(str)))
		return (1);
	if (!(ctx->nelms = sz / 20))
		return (1);
	if (!(ctx->elms = malloc(ctx->nelms * sizeof(t_elm))))
		return (1);
	elms = ctx->elms;
	while (*str)
	{
		if (fillit_parse_elm(&elm, &str))
			return (1);
		*elms++ = elm;
	}
	return (0);
}
