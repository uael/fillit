/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 08:04:38 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "fillit.h"

#define MAP_MAX_SIZE (26 * 21)
#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

static t_u08	fillit_validate(t_u16 tetr)
{
	t_i08 x;
	t_i08 y;
	t_u08 c;
	t_u08 n;

	c = 0;
	n = 0;
	x = -1;
	while (++x < 4 && (y = -1) < 0)
		while (++y < 4)
			if (BIT_AT(tetr, x, y, 4))
			{
				++n;
				if (x < 3 && BIT_AT(tetr, x + 1, y, 4))
					++c;
				if (y < 3 && BIT_AT(tetr, x, y + 1, 4))
					++c;
			}
	return ((t_u08)(c < 3 || n != 4));
}

static t_u08	fillit_parse_tetr(t_u16 *tetr, t_car **str)
{
	t_u08	i;
	t_car	c;

	if ((*str)[4] != '\n' || (*str)[9] != '\n' ||
		(*str)[14] != '\n' || (*str)[19] != '\n')
		return (1);
	FT_INIT(tetr, t_u16);
	i = 0;
	while (i < 16)
		if ((c = *(*str)++) == '#')
			*tetr |= 1 << i++;
		else if (c == '.')
			++i;
		else if (c != '\n')
			return (1);
	if (fillit_validate(*tetr))
		return (1);
	while (**str == '\n')
		++*str;
	while (!(*tetr & 0x000F))
		*tetr >>= 4;
	while (!(*tetr & 0x1111))
		*tetr >>= 1;
	return (0);
}

static t_u08	fillit_parse_str(t_tetrs *tetrs, t_car *str, t_usz len)
{
	t_u16	tetr;
	t_u16	*buf;

	if (!(tetrs->len = (len + 1) / 21) || tetrs->len > 26)
		return (1);
	if (!(tetrs->buf = malloc(tetrs->len * sizeof(t_u16))))
		return (1);
	buf = tetrs->buf;
	while (*str)
	{
		if (fillit_parse_tetr(&tetr, &str))
			return (1);
		*buf++ = tetr;
	}
	return (0);
}

t_u08			fillit_parse(t_tetrs *tetrs, t_car const *filename)
{
	t_i32	fd;
	t_car	*str;
	t_car	buf[MAP_MAX_SIZE + 1];
	t_u08	ret;
	ssize_t	r;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (1);
	if ((r = read(fd, buf, MAP_MAX_SIZE + 1)) < 0 || r > MAP_MAX_SIZE)
		return (1);
	buf[r] = '\0';
	if ((r + 1) % 21 || !(str = malloc((size_t)(r + 1) * sizeof(t_car))))
		return (1);
	if (close(fd) < 0)
		return (1);
	ft_strcpy(str, buf);
	ret = fillit_parse_str(tetrs, str, (size_t)r);
	free(str);
	return (ret);
}
