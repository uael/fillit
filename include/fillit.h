/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:05 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/13 17:06:53 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <libft.h>

typedef _Bool	t_bool;

typedef struct	s_tetr
{
	t_u16		bin;
	t_car		letter;
}				t_tetr;

typedef struct	s_tetrs
{
	t_u16		*buf;
	t_usz		len;
}				t_tetrs;

typedef struct	s_map
{
	t_car		*buf;
	t_usz		len;
	t_u08		filled[26];
}				t_map;

extern t_u08	fillit_parse(t_tetrs *tetrs, t_car const *filename);
extern t_usz	fillit_solve(t_tetrs *c, t_car **map);

#endif
