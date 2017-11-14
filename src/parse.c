/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:09 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 14:38:45 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "fillit.h"

#define MAP_MAX_SIZE (26 * 21)
#define BIT_AT(SET, X, Y, N) (((SET) >> (((X) * (N)) + (Y))) & 1)

static uint8_t	fillit_validate(uint16_t tetr)
{
	int8_t	x;
	int8_t	y;
	uint8_t	c;
	uint8_t	n;

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
	return ((uint8_t)(c < 3 || n != 4));
}

static uint8_t	fillit_parse_tetr(uint16_t *tetr, char **str)
{
	uint8_t	i;
	char	c;

	if ((*str)[4] != '\n' || (*str)[9] != '\n' ||
		(*str)[14] != '\n' || (*str)[19] != '\n')
		return (1);
	FT_INIT(tetr, uint16_t);
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

uint8_t			fillit_parse(t_tetrs *tetrs, char const *filename)
{
	int32_t		fd;
	char		buf[MAP_MAX_SIZE + 1];
	char		*str;
	ssize_t		r;
	uint16_t	*tetr;

	if ((fd = open(filename, O_RDONLY)) <= 0)
		return (1);
	if ((r = read(fd, buf, MAP_MAX_SIZE + 1)) < 0 || r > MAP_MAX_SIZE)
		return (1);
	buf[r] = '\0';
	if (close(fd) < 0 || (r + 1) % 21)
		return (1);
	if (!(tetrs->len = ((size_t)r + 1) / 21) || tetrs->len > 26)
		return (1);
	if (!(tetrs->buf = malloc(tetrs->len * sizeof(uint16_t))))
		return (1);
	tetr = tetrs->buf;
	str = buf;
	while (*str)
		if (fillit_parse_tetr(tetr++, &str))
			return (1);
	return (0);
}
