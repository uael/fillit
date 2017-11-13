/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:54:26 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 17:52:17 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

static void		fillit_rem(t_car *map, t_usz n, t_car letter)
{
	t_usz i;

	i = 0;
	while (i < (n * n))
	{
		if (map[i] == letter)
			map[i] = '.';
		++i;
	}
}

static t_bool	fillit_put(t_car *map, t_usz n, t_tetr t, t_usz i)
{
	ssize_t	x;
	ssize_t	y;
	t_usz	dx;
	t_usz	dy;
	t_u08	c;

	c = 0;
	y = -1;
	dx = i % n;
	dy = i / n;
	while (++y < 4 && (y + dy) < n && (x = -1) < 0)
		while (++x < 4 && (x + dx) < n)
			if (BIT_AT(t.bin, y, x, 4) && map[((y + dy) * n) + (x + dx)] == '.')
			{
				map[((y + dy) * n) + (x + dx)] = t.letter;
				++c;
			}
	if (c == 4)
		return (1);
	fillit_rem(map, n, t.letter);
	return (0);
}

static t_bool	fillit_solve_nx(t_tetrs *c, t_car *map, t_usz n, t_u08 *filled)
{
	t_usz	i;
	t_u08	j;
	t_tetr	t;

	j = 0;
	FT_INIT(&t, t_tetr);
	while (j < c->len && filled[j])
		++j;
	if (j == c->len)
		return (1);
	t.bin = c->buf[j];
	t.letter = (t_car)('A' + j);
	i = 0;
	while (i < (n * n))
		if (fillit_put(map, n, t, i++) && (filled[j] = 1))
		{
			if (fillit_solve_nx(c, map, n, filled))
				return (1);
			fillit_rem(map, n, t.letter);
			filled[j] = 0;
		}
	return (0);
}

t_usz			fillit_solve(t_tetrs *c, t_car **map)
{
	t_usz	n;
	t_u08	filled[26];

	n = 1;
	if (!(*map = malloc((c->len * 4) * (c->len * 4) * sizeof(t_car))))
		return (1);
	while (++n)
	{
		ft_memset(*map, '.', (n * n) * sizeof(t_car));
		ft_memset(filled, 0, 26 * sizeof(t_u08));
		(*map)[n * n] = '\0';
		if (fillit_solve_nx(c, *map, n, filled))
			break ;
	}
	return (n);
}
