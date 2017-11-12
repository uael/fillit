/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/12 12:12:24 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "fillit.h"

static t_u08	fillit_parse_elm(t_elm *elm, t_dstr *str)
{
	t_u08	i;
	t_u08	n;
	t_car	c;

	if (str->len < 20)
		return (1);
	if (str->buf[4] != '\n' || str->buf[9] != '\n' ||
		str->buf[14] != '\n' || str->buf[19] != '\n')
		return (1);
	FT_INIT(elm, t_elm);
	i = 0;
	n = 0;
	while (i < 16)
		if ((c = *str->buf++) == '#' && ++n)
			*elm |= 1 << i++;
		else if (c == '.')
			++i;
		else if (c != '\n')
			return (1);
	while (*str->buf == '\n')
		++str->buf;
	return ((t_u08)(n > 4 ? 1 : 0));
}

t_u08			fillit_parse(t_ctx *ctx, t_dstr *str)
{
	t_elm	elm;
	t_elm	*elms;
	t_car	*buf;

	if (!(ctx->nelms = str->len + 1 / 21))
		return (1);
	if (!(ctx->elms = malloc(ctx->nelms * sizeof(t_elm))))
		return (1);
	buf = str->buf;
	elms = ctx->elms;
	while (*str->buf)
	{
		if (fillit_parse_elm(&elm, str))
			return (1);
		*elms++ = elm;
	}
	str->buf = buf;
	return (0);
}

t_u08			fillit_parse_file(t_ctx *ctx, t_car const *filename)
{
	t_i32	fd;
	t_dstr	buf;
	t_car	sbuf[4096];
	t_u08	ret;
	ssize_t	r;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (1);
	FT_INIT(&buf, t_dstr);
	while ((r = read(fd, sbuf, 4096)) != 0)
		if (r < 0)
			return (1);
		else
			ft_dstrpushncpy(&buf, sbuf, (t_usz)r);
	if (close(fd) < 0 || !buf.len)
		return (1);
	ret = fillit_parse(ctx, &buf);
	ft_dstrdtor(&buf);
	return (ret);
}
