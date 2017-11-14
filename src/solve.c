/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:54:26 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 13:27:42 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

static void		fillit_rem(char *map, size_t n, char letter, size_t i)
{
	while (i < (n * n))
	{
		if (map[i] == letter)
			map[i] = '.';
		++i;
	}
}

static t_bool	fillit_put(char *map, size_t n, t_tetr t, size_t i)
{
	ssize_t	x;
	ssize_t	y;
	size_t	dx;
	size_t	dy;
	uint8_t	c;

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
	fillit_rem(map, n, t.letter, i);
	return (0);
}

static t_bool	fillit_doit(t_tetrs *tetrs, char *map, size_t n, uint8_t *fill)
{
	size_t	i;
	uint8_t	j;
	t_tetr	t;

	j = 0;
	FT_INIT(&t, t_tetr);
	while (j < tetrs->len && fill[j])
		++j;
	if (j == tetrs->len)
		return (1);
	t.bin = tetrs->buf[j];
	t.letter = (char)('A' + j);
	i = 0;
	while (i < (n * n))
		if (fillit_put(map, n, t, i++) && (fill[j] = 1))
		{
			if (fillit_doit(tetrs, map, n, fill))
				return (1);
			fillit_rem(map, n, t.letter, i - 1);
			fill[j] = 0;
		}
	return (0);
}

size_t			fillit_solve(t_tetrs *tetrs, char **map)
{
	size_t	n;
	uint8_t	fill[26];

	n = 1;
	if (!(*map = malloc((tetrs->len * 4) * (tetrs->len * 4) * sizeof(char))))
		return (1);
	while (++n)
	{
		ft_memset(*map, '.', (n * n) * sizeof(char));
		ft_memset(fill, 0, 26 * sizeof(uint8_t));
		(*map)[n * n] = '\0';
		if (fillit_doit(tetrs, *map, n, fill))
			break ;
	}
	return (n);
}
