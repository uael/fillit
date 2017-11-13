/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:54:26 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 15:41:29 by alucas-          ###   ########.fr       */
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

static t_bool	fillit_put(t_u16 t, t_solve_ctx s, t_usz i, t_u08 wut)
{
	ssize_t	x;
	ssize_t	y;
	t_usz	dx;
	t_usz	dy;
	t_u08	c;

	c = 0;
	x = -1;
	dx = i / s.n;
	dy = i % s.n;
	while (++x < 4 && (x + dx) < s.n && (y = -1) < 0)
		while (++y < 4 && (y + dy) < s.n)
			if (BIT_AT(t, x, y, 4) &&
				s.map[((x + dx) * s.n) + (y + dy)] == '.')
			{
				s.map[((x + dx) * s.n) + (y + dy)] = (t_car)('A' + wut);
				++c;
			}
	if (c == 4)
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

static t_bool	fillit_solve_x(t_ctx *c, t_solve_ctx s, t_usz i)
{
	t_bool	a;
	t_usz	l;

	if (i == (s.n * s.n))
		return (0);
	a = 0;
	l = 0;
	while (l < c->n)
	{
		if (!s.ok[l] && (a = 1) && fillit_put(c->tetrs[l], s, i, (t_u08)l))
		{
			s.ok[l] = 1;
			if (fillit_solve_x(c, s, i + 1))
				return (1);
			fillit_rem(s.map, s.n, (t_u08)l);
			s.ok[l] = 0;
		}
		++l;
	}
	return (t_bool)(a ? fillit_solve_x(c, s, i + 1) : fillit_echo(s.map, s.n));
}

t_u08			fillit_solve(t_ctx *c)
{
	t_solve_ctx	s;

	FT_INIT(&s, t_solve_ctx);
	s.n = 1;
	if (!(s.map = malloc((c->n * 4) * (c->n * 4) * sizeof(t_car))))
		return (1);
	while (++s.n)
	{
		ft_memset(s.map, '.', (s.n * s.n) * sizeof(t_car));
		ft_memset(s.ok, 0, 26 * sizeof(t_u08));
		s.map[s.n * s.n] = '\0';
		if (fillit_solve_x(c, s, 0))
			break ;
	}
	free(s.map);
	return (0);
}
