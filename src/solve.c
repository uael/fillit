/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:54:26 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 14:27:37 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

static void		fillit_rem(t_car *map, t_usz n, t_u08 ok)
{
	t_usz i;

	i = 0;
	while (i < (n * n))
	{
		if (map[i] == (t_car)('A' + ok))
			map[i] = '.';
		++i;
	}
}

static t_bool	fillit_put(t_tetr *t, t_solve_ctx s, t_u08 wut)
{
	ssize_t	x;
	ssize_t	y;
	t_usz	dx;
	t_usz	dy;
	t_u08	c;

	c = 0;
	x = -1;
	dx = s.i / s.n;
	dy = s.i % s.n;
	while (++x < 4 && (x + dx) < s.n && (y = -1) < 0)
		while (++y < 4 && (y + dy) < s.n)
			if (BIT_AT(t->form, x, y, 4) &&
				s.map[((x + dx) * s.n) + (y + dy)] == '.')
			{
				s.map[((x + dx) * s.n) + (y + dy)] = (t_car)('A' + wut);
				++c;
			}
	if (c == t->n)
		return (1);
	fillit_rem(s.map, s.n, wut);
	return (0);
}

static t_bool	fillit_echo(t_car *m, t_usz n)
{
	t_usz i;

	i = 0;
	while (i < n)
	{
		write(1, m + (i++ * n), n);
		ft_putchar('\n');
	}
	return (1);
}

static t_bool	fillit_solve_x(t_ctx *c, t_solve_ctx s)
{
	t_bool	a;
	t_usz	l;

	if (s.i == (s.n * s.n))
		return (0);
	a = 0;
	l = 0;
	while (l < c->n)
	{
		if (!s.ok[l] && (a = 1) &&
			fillit_put(c->tetrs + l, s, (t_u08)l))
		{
			s.ok[l] = 1;
			++s.i;
			if (fillit_solve_x(c, s))
				return (1);
			fillit_rem(s.map, s.n, (t_u08)l);
			--s.i;
			s.ok[l] = 0;
		}
		++l;
	}
	++s.i;
	return (t_bool)(a ? fillit_solve_x(c, s) : fillit_echo(s.map, s.n));
}

t_u08			fillit_solve(t_ctx *c)
{
	t_solve_ctx	sctx;

	FT_INIT(&sctx, t_solve_ctx);
	sctx.n = 1;
	while (++sctx.n)
	{
		if (!(sctx.map = ft_memrealloc(sctx.map, 0,
			((sctx.n * sctx.n) + 1) * sizeof(t_car))))
			return (0);
		ft_memset(sctx.map, '.', (sctx.n * sctx.n) * sizeof(t_car));
		ft_memset(sctx.ok, 0, 26 * sizeof(t_u08));
		sctx.map[sctx.n * sctx.n] = '\0';
		if (fillit_solve_x(c, sctx))
			break ;
	}
	return (0);
}
