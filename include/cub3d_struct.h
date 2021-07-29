/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olidon <olidon@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 18:00:32 by olidon            #+#    #+#             */
/*   Updated: 2020/02/25 14:17:19 by olidon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct	s_map
{
	char			*map;
	struct s_map	*next;
}				t_map;

typedef struct	s_player
{
	int			x;
	int			y;
	float		a;
}				t_player;

typedef struct	s_sprpos
{
	int				x;
	int				y;
	int				ox;
	int				oy;
	float			dist;
	float			angle;
	int				vis;
	struct s_sprpos	*next;
}				t_sprpos;

typedef struct	s_sprite
{
	int				offset;
	int				gridx;
	int				gridy;
	float			dist;
	struct s_sprite	*next;
}				t_sprite;

typedef struct	s_img
{
	int				rx;
	int				ry;
	void			*ptr;
	unsigned int	*data;
	int				bpp;
	int				l;
	int				end;
}				t_img;

typedef struct	s_text
{
	char		*nop;
	int			exno;
	t_img		no;
	char		*sop;
	int			exso;
	t_img		so;
	char		*wep;
	int			exwe;
	t_img		we;
	char		*eap;
	int			exea;
	t_img		ea;
	char		*sp;
	int			exsp;
	t_img		s;
}				t_text;

typedef struct	s_color
{
	unsigned int	c;
	unsigned int	f;
	int				exc;
	int				exf;
}				t_color;

typedef struct	s_coord
{
	float		ax;
	float		ay;
	float		ya;
	float		xa;
}				t_coord;

typedef struct	s_mvmnt
{
	int			a;
	int			d;
	int			w;
	int			s;
	int			an;
}				t_mvmnt;

typedef struct	s_const
{
	float		scdist;
	float		schl;
	float		seglen;
	float		fov;
}				t_const;

typedef struct	s_elem
{
	int			save;
	t_const		cst;
	float		rayan;
	void		*m_ptr;
	void		*w_ptr;
	t_img		cimg;
	t_img		mimg;
	t_coord		rayx;
	t_coord		rayy;
	t_mvmnt		mvmnt;
	t_sprite	*sp;
	t_sprpos	*sprpos;
	int			offset;
	char		wallc;
	int			exmap;
	int			endmap;
	char		**map;
	char		**mapcp;
	int			msy;
	int			msx;
	int			rx;
	int			ry;
	int			exres;
	t_text		t;
	t_player	p;
	int			exp;
	t_color		c;
	char		*bmp;
}				t_elem;

#endif
