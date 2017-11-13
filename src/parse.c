/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 10:19:45 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "fillit.h"

#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

static t_u08	fillit_validate(t_u16 form)
{
	t_i08 x;
	t_i08 y;
	t_u08 c;

	c = 0;
	x = -1;
	while (++x < 4 && (y = -1) < 0)
		while (++y < 4)
			if (BIT_AT(form, x, y, 4))
			{
				if (x < 3 && BIT_AT(form, x + 1, y, 4))
					++c;
				if (y < 3 && BIT_AT(form, x, y + 1, 4))
					++c;
			}
	return ((t_u08)(c < 3));
}

static void		fillit_format(t_tetr *tetr)
{
	t_i32 x;
	t_i32 y;

	if (tetr->form & 0xF)
		x = 0;
	else if (tetr->form & 0xF0)
		x = 1;
	else if (tetr->form & 0xF00)
		x = 2;
	else
		x = 3;
	if (tetr->form & 0x1111)
		y = 0;
	else if (tetr->form & 0x2222)
		y = 1;
	else if (tetr->form & 0x4444)
		y = 2;
	else
		y = 3;
	tetr->form >>= (x * 4) + y;
}

static t_u08	fillit_parse_tetr(t_tetr *tetr, t_car **str)
{
	t_u08	i;
	t_u08	n;
	t_car	c;

	if ((*str)[4] != '\n' || (*str)[9] != '\n' ||
		(*str)[14] != '\n' || (*str)[19] != '\n')
		return (1);
	FT_INIT(tetr, t_tetr);
	i = 0;
	n = 0;
	while (i < 16)
		if ((c = *(*str)++) == '#' && ++n)
			tetr->form |= 1 << i++;
		else if (c == '.')
			++i;
		else if (c != '\n')
			return (1);
	if (n > 4 || fillit_validate(tetr->form))
		return (1);
	while (**str == '\n')
		++*str;
	fillit_format(tetr);
	return (0);
}

static t_u08	fillit_parse(t_ctx *ctx, t_dstr *str)
{
	t_tetr	tetr;
	t_tetr	*tetrs;
	t_car	*buf;

	if ((ctx->ntetrs = str->len + 1) % 21 != 0)
		return (1);
	if (!(ctx->ntetrs /= 21) || ctx->ntetrs > 26)
		return (1);
	if (!(ctx->tetrs = malloc(ctx->ntetrs * sizeof(t_tetr))))
		return (1);
	buf = str->buf;
	tetrs = ctx->tetrs;
	while (*buf)
	{
		if (fillit_parse_tetr(&tetr, &buf))
			return (1);
		*tetrs++ = tetr;
	}
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
