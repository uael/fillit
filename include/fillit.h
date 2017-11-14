/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/14 13:30:33 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>
# include <stdint.h>

typedef uint8_t	t_bool;

typedef struct	s_tetr
{
	uint16_t	bin;
	char		letter;
}				t_tetr;

typedef struct	s_tetrs
{
	uint16_t	*buf;
	size_t		len;
}				t_tetrs;

extern uint8_t	fillit_parse(t_tetrs *tetrs, char const *filename);
extern size_t	fillit_solve(t_tetrs *tetrs, char **map);

#endif
